#include "features.hpp"

#include "evaluation.hpp"
#include "pawn_structure.hpp"
#include "Attack_Defence.hpp"
#include "rook_score.hpp"
#include "king_safety.hpp"

vector<double> getFeatures(Board &board)
{
    PieceSquareTable pieceSquareTable;
    pawn_structure pawnStructure;
    kingFeature king(board);

    double material =
        pieceSquareTable.evaluateBoard(board.board);

    double mobility =
        pieceSquareTable.evaluateMobility(board);

    double pawns =
        pawnStructure.evaluatePawnStructure(board);

    pair<int,int> p =
        pressure(board);

    double pressureValue = p.first;
    double threat = p.second;

    double rook =
        rook_score(board);

    double check =
        king.check_value(board);

    double kingSafety =
        king.king_safety(board);

    double kingPosition =
        king.position_value(board);

    return {
        material,
        mobility,
        pawns,
        pressureValue,
        threat,
        rook,
        check,
        kingSafety,
        kingPosition
    };
}