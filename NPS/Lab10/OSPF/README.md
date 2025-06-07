# Configuring Routers
## Router 1:
Router(config)# interface fastethernet0/0
Router(config-if)# ip address 192.168.1.1 255.255.255.0
Router(config-if)# no shutdown
Router(config-if)# exit

Router(config)# interface serial0/0/0
Router(config-if)# ip address 10.1.1.1 255.255.255.252
Router(config-if)# no shutdown
Router(config-if)# exit

## Router 2:
Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#inter
Router(config)#interface ser
Router(config)#interface serial 0/0
Router(config-if)#ip address 10.1.1.2 255.255.252
                                      ^
% Invalid input detected at '^' marker.
	
Router(config-if)#no shutdown

%LINK-5-CHANGED: Interface Serial0/0, changed state to down
Router(config-if)#exit
Router(config)#interface f
Router(config)#interface fastEthernet 0/0
Router(config-if)#ip address 192.168.1.2 255.255.255.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface FastEthernet0/0, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface FastEthernet0/0, changed state to up
exit

## Router 3:
Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#interface f
Router(config)#interface fastEthernet 0/0
Router(config-if)#ip address 192.168.2.1 255.255.255.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface FastEthernet0/0, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface FastEthernet0/0, changed state to up
exit
Router(config)#interface ser
Router(config)#interface serial 0/0
%Invalid interface type and number
Router(config)#ip address 172.16.1.2 255.255.255.252
                   ^
% Invalid input detected at '^' marker.
	
Router(config)#no shutdown
                   ^
% Invalid input detected at '^' marker.
	
Router(config)#exit
Router#
%SYS-5-CONFIG_I: Configured from console by console

## Router 4:
Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#interfac
Router(config)#interface f
Router(config)#interface fastEthernet 0/0
Router(config-if)#ip address 192.168.3.1 255.255.255.0
Router(config-if)#no shut
Router(config-if)#no shutdown 

Router(config-if)#
%LINK-5-CHANGED: Interface FastEthernet0/0, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface FastEthernet0/0, changed state to up
exit
Router(config)#inter
Router(config)#interface seri
Router(config)#interface serial 0/0
%Invalid interface type and number
Router(config)#ip address 10.1.1.6 255.255.255.252
                   ^
% Invalid input detected at '^' marker.
	
Router(config)#no shutdown
                   ^
% Invalid input detected at '^' marker.
	
Router(config)#exit
Router#
%SYS-5-CONFIG_I: Configured from console by console


# OSPF Config:
### Router 1:
```
Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#router ospf 1
Router(config-router)#router-id 1.1.1
                                ^
% Invalid input detected at '^' marker.
	
Router(config-router)#router-id 1.1.1.1
Router(config-router)#network 192.168.1.0 0.0.0.255 area 0
Router(config-router)#network 10.1.1.0 0.0.0.3 area 0
Router(config-router)#network 172.16.1.0 0.0.03 area 0
                                         ^
% Invalid input detected at '^' marker.
	
Router(config-router)#exit
Router(config)#router ospf
% Incomplete command.
Router(config)#router ospf 1
Router(config-router)#network 172.16.1.0 0.0.0.3 area 0
Router(config-router)#exit
```

## Router 2:
```
Router(config)#router ospf 1
Router(config-router)#router-d 2.2.2.2
                             ^
% Invalid input detected at '^' marker.
	
Router(config-router)#router-id 2.2.2.2
Router(config-router)#network 10.1.1.0 0.0.0.3 area 0
Router(config-router)#exit
```

## Router 3:
```
Router#enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#router ospf 1
Router(config-router)#router-id 3.3.3.3
Router(config-router)#network 192.168.2.0 0.0.255 area 0
                                          ^
% Invalid input detected at '^' marker.
	
Router(config-router)#network 192.168.2.0 0.0.0.255 area 0
Router(config-router)#network 172.16.1.0 0.0.0.3 area 0
Router(config-router)#exit
Router(config)#router ospf 1
Router(config-router)#network 10.1.1.8 0.0.0.3 area 0
Router(config-router)#exit
```
## Router 4:
```
Router#enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#router ospf 1
Router(config-router)#network 192.168.3.0 0.0.0.255 area 0
Router(config-router)#netowk
Router(config-router)#netw
Router(config-router)#network 10.1.1.4 0.0.0.3 area 0
Router(config-router)#net
Router(config-router)#network 10.1.1.8 0.0.0.5 area 0
OSPF: Invalid address/mask combination (discontiguous mask)
Router(config-router)#exit
```
