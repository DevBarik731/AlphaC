#!/usr/bin/env bash

set -e

REPO="https://github.com/DevBarik731/AlphaC.git"
INSTALL_DIR="$HOME/.local/share/AlphaC"
BIN_DIR="$HOME/.local/bin"

echo "======================================"
echo "          AlphaC Installer"
echo "======================================"
echo

# Don't allow the whole installer to run as root.
if [ "$EUID" -eq 0 ]; then
    echo "ERROR: Do not run this installer with sudo."
    echo
    echo "Use:"
    echo "  curl -fsSL https://raw.githubusercontent.com/DevBarik731/AlphaC/main/install.sh | bash"
    exit 1
fi

# --------------------------------------
# Check Arch Linux
# --------------------------------------

if ! command -v pacman >/dev/null 2>&1; then
    echo "ERROR: AlphaC installer currently supports Arch Linux only."
    exit 1
fi

# --------------------------------------
# Install dependencies
# --------------------------------------

echo "[1/5] Installing dependencies..."

sudo pacman -S --needed \
    gcc \
    cmake \
    git \
    sfml \
    ttf-dejavu

# --------------------------------------
# Clone repository
# --------------------------------------

echo
echo "[2/5] Downloading AlphaC..."

mkdir -p "$HOME/.local/share"

if [ -d "$INSTALL_DIR/.git" ]; then
    echo "AlphaC already exists."
    echo "Updating repository..."

    git -C "$INSTALL_DIR" pull --ff-only
else
    rm -rf "$INSTALL_DIR"

    git clone "$REPO" "$INSTALL_DIR"
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

# --------------------------------------
# Build
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

if [ ! -x "$INSTALL_DIR/app" ]; then
    echo
    echo "ERROR: AlphaC failed to build."
    exit 1
fi

# --------------------------------------
# Create alphac command
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

    [ -f "$rc" ] || return 0

    if ! grep -qF 'export PATH="$HOME/.local/bin:$PATH"' "$rc"; then
        printf '\n# AlphaC\n' >> "$rc"
        printf 'export PATH="$HOME/.local/bin:$PATH"\n' >> "$rc"
    fi
}

add_path "$HOME/.zshrc"
add_path "$HOME/.bashrc"

# --------------------------------------
# Finish
# --------------------------------------

echo
echo "======================================"
echo "      AlphaC installed successfully!"
echo "======================================"
echo
echo "Run AlphaC with:"
echo
echo "    alphac"
echo
echo "Executable:"
echo
echo "    $INSTALL_DIR/app"
echo

case ":$PATH:" in
    *":$BIN_DIR:"*)
        echo "You can run 'alphac' now."
        ;;
    *)
        echo "Open a new terminal, or run:"
        echo
        echo "    export PATH=\"\$HOME/.local/bin:\$PATH\""
        echo
        echo "Then:"
        echo
        echo "    alphac"
        ;;
esac
```
