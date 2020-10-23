//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_QLISTWIDGETSUBACTIVITY_H
#define MYD14RY_QLISTWIDGETSUBACTIVITY_H

#include <QListWidgetItem>

//TODO inclusione del file di header del tipo dell'oggetto

class QListWidgetSubActivity : public QListWidgetItem {

public:
    SubActivity *getSubActivity();

private:
    SubActivity *subActivity;
};


#endif //MYD14RY_QLISTWIDGETSUBACTIVITY_H
