
#!/usr/bin/env bash

set -e

REPO_URL="https://github.com/DevBarik731/AlphaC.git"
INSTALL_DIR="$HOME/.local/share/AlphaC"
BIN_DIR="$HOME/.local/bin"
APP="$INSTALL_DIR/app"

echo "======================================"
echo "           AlphaC Installer"
echo "======================================"
echo

# --------------------------------------
# Check Arch Linux
# --------------------------------------

if ! command -v pacman >/dev/null 2>&1; then
    echo "Error: This installer is for Arch Linux."
    exit 1
fi

# --------------------------------------
# Install dependencies
# --------------------------------------

echo "[1/5] Installing dependencies..."

sudo pacman -S --needed \
    gcc \
    cmake \
    sfml \
    git

echo
echo "Dependencies installed."
echo

# --------------------------------------
# Clone / update repository
# --------------------------------------

echo "[2/5] Getting AlphaC..."

mkdir -p "$HOME/.local/share"

if [ -d "$INSTALL_DIR/.git" ]; then
    echo "AlphaC already exists. Updating..."
    git -C "$INSTALL_DIR" pull --ff-only
else
    rm -rf "$INSTALL_DIR"
    git clone "$REPO_URL" "$INSTALL_DIR"
fi

cd "$INSTALL_DIR"

# --------------------------------------
# Create CMakeLists.txt
# --------------------------------------

echo
echo "[3/5] Creating CMakeLists.txt..."

cat > CMakeLists.txt <<'EOF'
cmake_minimum_required(VERSION 3.20)

project(app LANGUAGES CXX)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

file(GLOB VALID_FILES CONFIGURE_DEPENDS
    "src/*.cpp"
    "src/evaluation/*.cpp"
    "Neural_Network/*.cpp"
)

add_executable(app
    main.cpp
    ${VALID_FILES}
)

target_compile_features(app PRIVATE cxx_std_17)

target_link_libraries(app PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
EOF

echo "CMakeLists.txt created."

# --------------------------------------
# Configure project
# --------------------------------------

echo
echo "[4/5] Building AlphaC..."

rm -rf build

cmake \
    -S . \
    -B build \
    -DCMAKE_BUILD_TYPE=Release

cmake \
    --build build \
    --parallel "$(nproc)"

if [ ! -f "$APP" ]; then
    echo
    echo "ERROR: AlphaC build failed."
    exit 1
fi

chmod +x "$APP"

echo
echo "Build successful."
echo "Executable: $APP"

# --------------------------------------
# Create alphac launcher
# --------------------------------------

echo
echo "[5/5] Installing alphac command..."

mkdir -p "$BIN_DIR"

cat > "$BIN_DIR/alphac" <<EOF
#!/usr/bin/env bash
cd "$INSTALL_DIR"
exec ./app "\$@"
EOF

chmod +x "$BIN_DIR/alphac"

# --------------------------------------
# Add ~/.local/bin to PATH
# --------------------------------------

add_path() {
    local rc="$1"

    if [ -f "$rc" ]; then
        if ! grep -qF 'export PATH="$HOME/.local/bin:$PATH"' "$rc"; then
            printf '\n# AlphaC\nexport PATH="$HOME/.local/bin:$PATH"\n' >> "$rc"
        fi
    fi
}

add_path "$HOME/.bashrc"
add_path "$HOME/.zshrc"

# --------------------------------------
# Add alias
# --------------------------------------

add_alias() {
    local rc="$1"

    if [ -f "$rc" ]; then
        if ! grep -qF "alias alphac=" "$rc"; then
            printf '\n# AlphaC\nalias alphac="$BIN_DIR/alphac"\n' >> "$rc"
        fi
    fi
}

add_alias "$HOME/.bashrc"
add_alias "$HOME/.zshrc"

# --------------------------------------
# Finish
# --------------------------------------

echo
echo "======================================"
echo "       AlphaC Installed Successfully"
echo "======================================"
echo
echo "Run AlphaC with:"
echo
echo "    alphac"
echo
echo "Or:"
echo
echo "    $APP"
echo

echo "Open a new terminal, or run:"
echo
echo "    source ~/.zshrc"
echo

