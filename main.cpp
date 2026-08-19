#include "validate.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <map>

using namespace std;
enum Piece {
    EMPTY = 0,
    BLACK_PAWN=-1,
    BLACK_ROOK=-2,
    BLACK_KNIGHT=-3,
    BLACK_BISHOP=-4,
    BLACK_QUEEN=-5,
    BLACK_KING=-6,
    WHITE_PAWN = 1,
    WHITE_ROOK=2,
    WHITE_KNIGHT=3,
    WHITE_BISHOP=4,
    WHITE_QUEEN=5,
    WHITE_KING=6
};
string getTextureName(int piece)
{
    switch (piece)
    {
        case BLACK_PAWN:   return "texture/B_pawn.png";
        case BLACK_ROOK:   return "texture/B_rook.png";
        case BLACK_KNIGHT: return "texture/B_knight.png";
        case BLACK_BISHOP: return "texture/B_bishop.png";
        case BLACK_QUEEN:  return "texture/B_queen.png";
        case BLACK_KING:   return "texture/B_king.png";
        case WHITE_PAWN:   return "texture/W_pawn.png";
        case WHITE_ROOK:   return "texture/W_rook.png";
        case WHITE_KNIGHT: return "texture/W_knight.png";
        case WHITE_BISHOP: return "texture/W_bishop.png";
        case WHITE_QUEEN:  return "texture/W_queen.png";
        case WHITE_KING:   return "texture/W_king.png";
    }
    return "";
}
bool isWhite(int piece)
{
    return piece == WHITE_PAWN ||
           piece == WHITE_ROOK ||
           piece == WHITE_KNIGHT ||
           piece == WHITE_BISHOP ||
           piece == WHITE_QUEEN ||
           piece == WHITE_KING;
}
bool isBlack(int piece)
{
    return piece == BLACK_PAWN ||
           piece == BLACK_ROOK ||
           piece == BLACK_KNIGHT ||
           piece == BLACK_BISHOP ||
           piece == BLACK_QUEEN ||
           piece == BLACK_KING;
}
int main()
{
    Board a;
    sf::RenderWindow window(
        sf::VideoMode({480, 480}),
        "Chess Board"
    );
    map<int, sf::Texture> textures;
    vector<int> pieces = {
        BLACK_PAWN,
        BLACK_ROOK,
        BLACK_KNIGHT,
        BLACK_BISHOP,
        BLACK_QUEEN,
        BLACK_KING,
        WHITE_PAWN,
        WHITE_ROOK,
        WHITE_KNIGHT,
        WHITE_BISHOP,
        WHITE_QUEEN,
        WHITE_KING
    };

    for (int piece : pieces)
    {
        sf::Texture texture;

        string filename = getTextureName(piece);

        if (!texture.loadFromFile(filename))
        {
            cerr << "Failed to load: " << filename << endl;
            return 1;
        }
        textures[piece] = texture;
    }
    bool selected = false;

    int selectedRow = -1;
    int selectedCol = -1;
    bool whiteTurn = true;
    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            if (const auto* mouse =
                    event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouse->button != sf::Mouse::Button::Left)
                    continue;

                int mouseX = mouse->position.x;
                int mouseY = mouse->position.y;
                if (mouseX < 0 || mouseX >= 480 ||
                    mouseY < 0 || mouseY >= 480)
                    continue;

                int row = mouseY / 60;
                int col = mouseX / 60;

                if (!selected)
                {
                    int piece = a.board[row][col];

                    if (piece == EMPTY)
                        continue;

                    if (whiteTurn && !isWhite(piece))
                        continue;

                    if (!whiteTurn && !isBlack(piece))
                        continue;

                    selected = true;

                    selectedRow = row;
                    selectedCol = col;

                    cout << "Selected: "
                         << row << " "
                         << col << endl;
                }

                else
                {
                    if (row == selectedRow &&
                        col == selectedCol)
                    {
                        selected = false;
                        selectedRow = -1;
                        selectedCol = -1;

                        continue;
                    }

                    int destinationPiece = a.board[row][col];

                    if (destinationPiece != EMPTY)
                    {
                        if (whiteTurn && isWhite(destinationPiece))
                        {
                            selectedRow=row;
                            selectedCol=col;
                            continue;
                        }
                        if (!whiteTurn && isBlack(destinationPiece))
                        {
                            selectedRow=row;
                            selectedCol=col;
                            continue;
                        }
                    }
                    bool valid;
                    if(whiteTurn)
                    valid = validate(
                        a,
                        selectedRow,
                        selectedCol,
                        row,
                        col,
                        a.whiteKingPos.first,
                        a.whiteKingPos.second
                    );
                    else
                    valid = validate(
                        a,
                        selectedRow,
                        selectedCol,
                        row,
                        col,
                        a.blackKingPos.first,
                        a.blackKingPos.second
                    );
                    if (valid)
                    {
                        cout << "Valid move: "
                             << selectedRow << ","
                             << selectedCol
                             << " -> "
                             << row << ","
                             << col << endl;

                        int piece=a.board[selectedRow][selectedCol];
                             
                        a.board[row][col] =
                            a.board[selectedRow][selectedCol];

                        a.board[selectedRow][selectedCol] = EMPTY;

                        if(piece==WHITE_KING)
                        {
                            a.whiteKingPos={row,col};
                        }

                        if(piece==BLACK_KING)
                        {
                            a.blackKingPos={row,col};
                        }

                        if(piece==WHITE_PAWN||piece==BLACK_PAWN)
                        {
                            promote_pawn(a,row,col);
                        }
                        whiteTurn = !whiteTurn;
                    }
                    else
                    {
                        cout << "Invalid move\n";
                    }
                    selected = false;

                    selectedRow = -1;
                    selectedCol = -1;
                }
            }
        }


        window.clear();

        for (int r = 0; r < 8; r++)
        {
            for (int c = 0; c < 8; c++)
            {
                sf::RectangleShape square(
                    sf::Vector2f(60.f, 60.f)
                );

                square.setPosition(
                    sf::Vector2f(
                        c * 60.f,
                        r * 60.f
                    )
                );

                if ((r + c) % 2 == 0)
                {
                    square.setFillColor(
                        sf::Color(240, 217, 181)
                    );
                }
                else
                {
                    square.setFillColor(
                        sf::Color(181, 136, 99)
                    );
                }

                if (selected &&
                    r == selectedRow &&
                    c == selectedCol)
                {
                    square.setFillColor(
                        sf::Color(246, 246, 105)
                    );
                }

                window.draw(square);
            }
        }


    if (selected)
    {
        for (int r = 0; r < 8; r++)
        {
            for (int c = 0; c < 8; c++)
            {

                if (r == selectedRow && c == selectedCol)
                continue;

                int destinationPiece = a.board[r][c];

                if (destinationPiece != EMPTY)
                {
                    if (whiteTurn && isWhite(destinationPiece))
                        continue;

                    if (!whiteTurn && isBlack(destinationPiece))
                        continue;
                }
                if (whiteTurn&&validate(
                    a,
                    selectedRow,
                    selectedCol,
                    r,
                    c,a.whiteKingPos.first,a.whiteKingPos.second)||!whiteTurn&&validate(a,
                    selectedRow,
                    selectedCol,
                    r,
                    c,a.blackKingPos.first,a.blackKingPos.second))
                {
                    if (destinationPiece != EMPTY)
                    {
                        sf::CircleShape circle(25.f);

                        circle.setPosition({
                        c * 60.f + 5.f,
                        r * 60.f + 5.f
                        });

                        circle.setFillColor(
                        sf::Color(180, 50, 50, 150)
                        );

                        window.draw(circle);
                }

                    else
                    {
                        sf::CircleShape circle(9.f);

                        circle.setPosition({
                        c * 60.f + 21.f,
                        r * 60.f + 21.f
                        });

                        circle.setFillColor(
                        sf::Color(50, 50, 50, 170)
                        );

                        window.draw(circle);
                }
            }
        }
    }
}


        for (int r = 0; r < 8; r++)
        {
            for (int c = 0; c < 8; c++)
            {
                int piece = a.board[r][c];

                if (piece == EMPTY)
                    continue;

                sf::Sprite sprite(textures[piece]);

                sf::Vector2u size =
                    textures[piece].getSize();

                float scaleX =
                    60.f / size.x;

                float scaleY =
                    60.f / size.y;

                sprite.setScale(
                    sf::Vector2f(scaleX, scaleY)
                );

                sprite.setPosition(
                    sf::Vector2f(
                        c * 60.f,
                        r * 60.f
                    )
                );

                window.draw(sprite);
            }
        }

        window.display();
    }

    return 0;
}