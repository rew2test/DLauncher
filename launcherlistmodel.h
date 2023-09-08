#ifndef LAUNCHERLISTMODEL_H
#define LAUNCHERLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QQmlEngine>
#include <QVector>

class LauncherListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_DISABLE_COPY(LauncherListModel)
    Q_PROPERTY(QString filterStr READ filterStr WRITE setFilterStr)
    QML_ELEMENT
public:
    explicit LauncherListModel(QObject *parent = nullptr);

public :
    enum UserRoles {
        NameRole = Qt::UserRole + 1,
        IconRole,
    };
    Q_ENUM(UserRoles)

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void populate();

    void setFilterStr(const QString &str);
    QString filterStr();

    Q_INVOKABLE QString get(size_t index);

    Q_INVOKABLE void init();

private:
    QStringList m_data;
    QVector<int> m_filter;
    QString m_filterStr;
};

#endif // LAUNCHERLISTMODEL_H