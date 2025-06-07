# Configuring RIP

### Router 0:
Router>enable
Router#config terminal
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#inter
Router(config)#interface faster
Router(config)#interface fastet
Router(config)#interface fastethernet 0/0
Router(config-if)#ip address 192.168.1.1 255.255.255.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface FastEthernet0/0, changed state to up
exit
Router(config)#interf
Router(config)#interface serial0/0
Router(config-if)#ip address 10.0.0.1 255.0.0.0
Router(config-if)#no shutdo
Router(config-if)#no shutdown 

%LINK-5-CHANGED: Interface Serial0/0, changed state to down
Router(config-if)#exit


## Router 1:
Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#interface fas
Router(config)#interface fastEthernet 0/0
Router(config-if)#ip address 192.168.1.2 255.255.255.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface FastEthernet0/0, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface FastEthernet0/0, changed state to up
exit
Router(config)#interface serial 0/0
Router(config-if)#ip address 10.0.0.2 255.0.0.0
Router(config-if)#no shutdown

%LINK-5-CHANGED: Interface Serial0/0, changed state to down
Router(config-if)#exit

## Router 2:
Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#interface 0/0
                         ^
% Invalid input detected at '^' marker.
	
Router(config)#interface fas
Router(config)#interface fastEthernet 0/0
Router(config-if)#ip address 192.168.2.1 255.255.255.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface FastEthernet0/0, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface FastEthernet0/0, changed state to up
exit
Router(config)#interface ser
Router(config)#interface serial 0/0
Router(config-if)#ip address 172.16.0.2 255.255.0.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface Serial0/0, changed state to up
exit
Router(config)#
%LINEPROTO-5-UPDOWN: Line protocol on Interface Serial0/0, changed state to up


## Router 3:
Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#interface f
Router(config)#interface fastEthernet 0/0
Router(config-if)#ip address 192.168.3.1 255.255.255.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface FastEthernet0/0, changed state to up

%LINEPROTO-5-UPDOWN: Line protocol on Interface FastEthernet0/0, changed state to up
exit
Router(config)#interface se
Router(config)#interface serial 0/0
Router(config-if)#ip address 12.0.0.2 255.0.0.0
Router(config-if)#no shutdown

Router(config-if)#
%LINK-5-CHANGED: Interface Serial0/0, changed state to up
exit

### RIP Settings:
Router 0:
```

Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#router rip
Router(config-router)#version 2
Router(config-router)#network 192.168.1.0
Router(config-router)#network
Router(config-router)#network 10.0.0.0
Router(config-router)#net
Router(config-router)#network 172.16.0.0
Router(config-router)#exit
```
Router 1:
```
Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#router rip
Router(config-router)#version 2
Router(config-router)#network 192.168.2.0
Router(config-router)#network 172.16.0.0
Router(config-router)#network 12.0.0.0
Router(config-router)#exit
```
Router 2:
```
Router>enable
Router#config t
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#router rip
Router(config-router)#version 2
Router(config-router)#network 192.168.2.0
Router(config-router)#network 172.16.0.0
Router(config-router)#12.0.0.0
                      ^
% Invalid input detected at '^' marker.
	
Router(config-router)#network12.0.0.0
                             ^
% Invalid input detected at '^' marker.
	
Router(config-router)#network 12.0.0.0
Router(config-router)#exit
Router(config)#
```
Router 3:
```
Router(config)#router rip
Router(config-router)#version 2
Router(config-router)#network 192.168.3.0
Router(config-router)#11.0.0.0
                      ^
% Invalid input detected at '^' marker.
	
Router(config-router)#net
Router(config-router)#network 11.0.0.0
Router(config-router)#ne
Router(config-router)#network 12.0.0.0
Router(config-router)#exit
```

# Confirmation:
```
Router#show ip route
Codes: C - connected, S - static, I - IGRP, R - RIP, M - mobile, B - BGP
       D - EIGRP, EX - EIGRP external, O - OSPF, IA - OSPF inter area
       N1 - OSPF NSSA external type 1, N2 - OSPF NSSA external type 2
       E1 - OSPF external type 1, E2 - OSPF external type 2, E - EGP
       i - IS-IS, L1 - IS-IS level-1, L2 - IS-IS level-2, ia - IS-IS inter area
       * - candidate default, U - per-user static route, o - ODR
       P - periodic downloaded static route

Gateway of last resort is not set

C    172.16.0.0/16 is directly connected, Serial0/0
C    192.168.2.0/24 is directly connected, FastEthernet0/0
```
<br><br>
```
show ip protocols
Routing Protocol is "rip"
Sending updates every 30 seconds, next due in 2 seconds
Invalid after 180 seconds, hold down 180, flushed after 240
Outgoing update filter list for all interfaces is not set
Incoming update filter list for all interfaces is not set
Redistributing: rip
Default version control: send version 2, receive 2
  Interface             Send  Recv  Triggered RIP  Key-chain
  FastEthernet0/0       22
  Serial0/0             22
Automatic network summarization is in effect
Maximum path: 4
Routing for Networks:
	11.0.0.0
	12.0.0.0
	192.168.3.0
Passive Interface(s):
Routing Information Sources:
	Gateway         Distance      Last Update
Distance: (default is 120)
```