/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Copyright 2013 - 2021, nymea GmbH
* Contact: contact@nymea.io
*
* This file is part of nymea.
* This project including source code and documentation is protected by
* copyright law, and remains the property of nymea GmbH. All rights, including
* reproduction, publication, editing and translation, are reserved. The use of
* this project is subject to the terms of a license agreement to be concluded
* with nymea GmbH in accordance with the terms of use of nymea GmbH, available
* under https://nymea.io/license
*
* GNU Lesser General Public License Usage
* Alternatively, this project may be redistributed and/or modified under the
* terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; version 3. This project is distributed in the hope that
* it will be useful, but WITHOUT ANY WARRANTY; without even the implied
* warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this project. If not, see <https://www.gnu.org/licenses/>.
*
* For any further details and any questions please contact us under
* contact@nymea.io or see our FAQ/Licensing Information on
* https://nymea.io/license/faq
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef NETWORKDEVICEMONITOR_H
#define NETWORKDEVICEMONITOR_H

#include <QObject>
#include <QDateTime>

#include "libnymea.h"
#include "network/networkdeviceinfo.h"

class LIBNYMEA_EXPORT NetworkDeviceMonitor : public QObject
{
    Q_OBJECT

    friend class NetworkDeviceDiscovery;

public:
    NetworkDeviceInfo networkDeviceInfo() const;

    bool reachable() const;
    QDateTime lastSeen() const;

signals:
    void reachableChanged(bool reachable);
    void lastSeenChanged(const QDateTime &lastSeen);
    void networkDeviceInfoChanged(const NetworkDeviceInfo &networkDeviceInfo);

private:
    explicit NetworkDeviceMonitor(const NetworkDeviceInfo &networkDeviceInfo, QObject *parent = nullptr);
    ~NetworkDeviceMonitor();

    NetworkDeviceInfo m_networkDeviceInfo;
    bool m_reachable = false;
    QDateTime m_lastSeen;

};

QDebug operator<<(QDebug debug, NetworkDeviceMonitor *networkDeviceMonitor);


#endif // NETWORKDEVICEMONITOR_H
