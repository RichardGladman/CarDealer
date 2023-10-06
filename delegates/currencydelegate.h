#ifndef CURRENCYDELEGATE_H
#define CURRENCYDELEGATE_H

#include <QStyledItemDelegate>

class CurrencyDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CurrencyDelegate(QObject *parent = nullptr);
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    int getColumn() const;
    void setColumn(int newColumn);

private:
    int column;
};

#endif // CURRENCYDELEGATE_H
