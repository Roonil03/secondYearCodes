# Config Devices:
## Router:
```
Router>enable
Router#configure t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#inter
Router(config)#interface f
Router(config)#interface fastEthernet 0/0
%Invalid interface type and number
Router(config)#interface fastEthernet 0/1
%Invalid interface type and number
Router(config)#int
Router(config)#interface gig
Router(config)#interface gigabitEthernet 0/0
Router(config-if)#ip address 192.168.10.1 255.255.255.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface GigabitEthernet0/0, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface GigabitEthernet0/0, changed state to up
exit
```
```
Router(config)#ip dhcp pool VOICe
Router(dhcp-config)#network 192.168.10.0 255.255.255.0
Router(dhcp-config)#default-router 192.168.10.1
Router(dhcp-config)#option 150 ip 192.168.10.1
Router(dhcp-config)#exit
```
```
Router(config)#telephony-service
Router(config-telephony)#max-dn 5
Router(config-telephony)#max-eph
Router(config-telephony)#max-ephones 5
Router(config-telephony)#ip source-address 192.168.10.1 port 2000
Router(config-telephony)#auto assign 4 to 6
Router(config-telephony)#auto assign 1 to 5
Router(config-telephony)#exit
```
```
Router(config)#ephone-dn 1
Router(config-ephone-dn)#%LINK-3-UPDOWN: Interface ephone_dsp DN 1.1, changed state to up

Router(config-ephone-dn)#number 1001
Router(config-ephone-dn)#exit
Router(config)#ep
Router(config)#ephon
Router(config)#ephone-dn 2
Router(config-ephone-dn)#%LINK-3-UPDOWN: Interface ephone_dsp DN 2.1, changed state to up
number 1002
Router(config-ephone-dn)#exit
Router(config)#
```
```

Router#show ephone

ephone-1 Mac:00D0.D37D.4059 TCP socket:[1] activeLine:0 REGISTERED in SCCP ver 12 and Server in ver 8
mediaActive:0 offhook:0 ringing:0 reset:0 reset_sent:0 paging 0 debug:0 caps:8
IP:192.168.10.2 1025 7960   keepalive 43 max_line 2
 button 1: dn 1  number 1001 CH1   IDLE

ephone-2 Mac:00E0.B087.90C0 TCP socket:[1] activeLine:0 REGISTERED in SCCP ver 12 and Server in ver 8
mediaActive:0 offhook:0 ringing:0 reset:0 reset_sent:0 paging 0 debug:0 caps:8
IP:192.168.10.3 1025 7960   keepalive 43 max_line 2
```

## Switch:
```
Switch(config)#interface range FastEthernet 0/1-2
Switch(config-if-range)#switchport mode access
Switch(config-if-range)#swit
Switch(config-if-range)#switchport voice vlan 1
Switch(config-if-range)#exit
```