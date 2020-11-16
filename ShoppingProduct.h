//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_SHOPPINGPRODUCT_H
#define MYD14RY_SHOPPINGPRODUCT_H

#include <QString>

class ShoppingProduct {
public:

    ShoppingProduct() = default;

    ShoppingProduct(const ShoppingProduct &original);

    ShoppingProduct &operator=(const ShoppingProduct &) = delete;

    ~ShoppingProduct() = default;

    const QString &getName() const;

    void setName(const QString &name);

    bool isCatched() const;

    void setCatched(bool catched);

private:
    QString name;
    bool catched;

};


#endif //MYD14RY_SHOPPINGPRODUCT_H
