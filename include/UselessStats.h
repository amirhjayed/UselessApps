/*
* Copyleft (l) Useless NV. All rights dispensed.
* Free and for useless use only. The contents of this document consitutes shared
* information of Useless Group of companies. If you use this in a useful way, you dissapoint me.
* Author: hajayedamir@gmail.com
*/

#include <QObject>

class UselessStats : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int opened_count READ getOpenedCount CONSTANT)

public:
    explicit UselessStats(const QString& stats_filepath, QObject* parent = nullptr);
    int getOpenedCount() const;

private:
    int m_opened_count;
};
