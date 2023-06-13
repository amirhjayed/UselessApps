/*
* Copyleft (l) Useless NV. All rights dispensed.
* Free and for useless use only. The contents of this document consitutes shared
* information of Useless Group of companies. If you use this in a useful way, you dissapoint me.
* Author: hajayedamir@gmail.com
*/

#pragma once

#include <QString>

class StartupHandler
{
public:
    StartupHandler() = default;
    ~StartupHandler() = default;

    bool setupApplication();
    QString getUselessStatsPath() const;

private:
    QString m_useless_stats_path;
};
