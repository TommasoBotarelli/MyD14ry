//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_SHOPPINGPRODUCT_H
#define MYD14RY_SHOPPINGPRODUCT_H

#include <QString>
#include <memory>

class ShoppingProduct {
public:
    ShoppingProduct() = default;

    const QString &getName() const;

    void setName(const QString &name);

    bool isCatched() const;

    void setCatched(bool c);

    ~ShoppingProduct() = default;

private:
    QString name;

    bool catched;
};


#endif //MYD14RY_SHOPPINGPRODUCT_H
