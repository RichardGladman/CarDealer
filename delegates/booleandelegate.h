#ifndef BOOLEANDELEGATE_H
#define BOOLEANDELEGATE_H

#include <QStyledItemDelegate>

class BooleanDelegate: public QStyledItemDelegate
{
public:
    BooleanDelegate(int column, QObject *parent = nullptr);

    // QAbstractItemDelegate interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
    int column;
};

#endif // BOOLEANDELEGATE_H
