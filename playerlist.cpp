#include "playerlist.h"
#include "player.h"
#include "monopoly.h"
#include <QVector>

PlayerList::PlayerList(const QVector<QString> &players_info)
{
    for(int i = 0; i < players_info.size(); ++i) {
        // fix color
        players.push_back(new Player(players_info[i], PlayerColor::BLUE));
    }
}

void PlayerList::start()
{
    Monopoly *monopoly = Monopoly::instance();
    if(monopoly == 0)
        qDebug() << "are" ;
//    monopoly->tass();
//    bool game_continiue = true;
//    int players_num = players.size();

//    for (int i = 0; i < players_num; ++i)
//        monopoly->addPlayer(players[i]);

//    Player::PlayerState state;
//    while (game_continiue) {
//        for(int p = 0; p < players_num; ++p) {
//            switch (players[p]->getState()) {
//                case Player::PlayerState::NotStarted :
//                monopoly->tass();
//                break;
//            case Player::PlayerState::Normal :
//                // do something
//                break;
//            case Player::PlayerState::InJail :
//                // do something
//                break;
//            case Player::PlayerState::Broke :
//                // do something
//                break;
//            }
//        }
//    }
}
