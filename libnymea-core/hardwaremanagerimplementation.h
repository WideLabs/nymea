/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Copyright 2013 - 2020, nymea GmbH
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
* GNU General Public License Usage
* Alternatively, this project may be redistributed and/or modified under the
* terms of the GNU General Public License as published by the Free Software
* Foundation, GNU version 3. This project is distributed in the hope that it
* will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along with
* this project. If not, see <https://www.gnu.org/licenses/>.
*
* For any further details and any questions please contact us under
* contact@nymea.io or see our FAQ/Licensing Information on
* https://nymea.io/license/faq
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef HARDWAREMANAGERIMPLEMENTATION_H
#define HARDWAREMANAGERIMPLEMENTATION_H

#include <QObject>
#include <QDBusConnection>
#include <QNetworkAccessManager>

#include "hardwaremanager.h"

namespace nymeaserver {

class Platform;
class MqttBroker;
class ZigbeeManager;
class ZigbeeHardwareResourceImplementation;
class ModbusRtuManager;
class ModbusRtuHardwareResourceImplementation;
class NetworkDeviceDiscoveryImpl;

class HardwareManagerImplementation : public HardwareManager
{
    Q_OBJECT

public:
    explicit HardwareManagerImplementation(Platform *platform, MqttBroker *mqttBroker, ZigbeeManager *zigbeeManager, ModbusRtuManager *modbusRtuManager, QObject *parent = nullptr);
    ~HardwareManagerImplementation() override;

    Radio433 *radio433() override;
    PluginTimerManager *pluginTimerManager() override;
    NetworkAccessManager *networkManager() override;
    UpnpDiscovery *upnpDiscovery() override;
    PlatformZeroConfController *zeroConfController() override;
    BluetoothLowEnergyManager *bluetoothLowEnergyManager() override;
    MqttProvider *mqttProvider() override;
    I2CManager *i2cManager() override;
    ZigbeeHardwareResource *zigbeeResource() override;
    ModbusRtuHardwareResource *modbusRtuResource() override;
    NetworkDeviceDiscovery *networkDeviceDiscovery() override;

public slots:
    void thingsLoaded();

private:
    QNetworkAccessManager *m_networkAccessManager = nullptr;

    Platform *m_platform = nullptr;

    // Hardware Resources
    PluginTimerManager *m_pluginTimerManager = nullptr;
    Radio433 *m_radio433 = nullptr;
    NetworkAccessManager *m_networkManager = nullptr;
    UpnpDiscovery *m_upnpDiscovery = nullptr;
    BluetoothLowEnergyManager *m_bluetoothLowEnergyManager = nullptr;
    MqttProvider *m_mqttProvider = nullptr;
    I2CManager *m_i2cManager = nullptr;
    ZigbeeHardwareResourceImplementation *m_zigbeeResource = nullptr;
    ModbusRtuHardwareResourceImplementation *m_modbusRtuResource = nullptr;
    NetworkDeviceDiscoveryImpl *m_networkDeviceDiscovery = nullptr;

};

}

#endif // HARDWAREMANAGERIMPLEMENTATION_H
