//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_SHOPPINGPRODUCT_H
#define MYD14RY_SHOPPINGPRODUCT_H

#include <QString>
#include <memory>

class ShoppingProduct {
public:
    explicit ShoppingProduct(QString n, QString cat, bool catBool, bool c = false) : name(n), category(cat),
                                                                                     categoryIsSet(catBool),
                                                                                     catched(c) {};

    const QString &getName() const;

    void setName(const QString &name);

    bool isCatched() const;

    void setCatched(bool c);

    ~ShoppingProduct() = default;

private:
    QString name;

    bool catched;

    QString category;

    bool categoryIsSet;
public:
    void setCategoryIsSet(bool categoryIsSet);

public:
    const QString &getCategory() const;

    void setCategory(const QString &category);

    bool isCategoryIsSet() const;
};


#endif //MYD14RY_SHOPPINGPRODUCT_H
