# Lab Exercises
1. Write a C program to avoid the congestion in network by using the leaky bucket method.
Suppose the network packets arrive at a leaky bucket policer at time interval t = 1, 2, 3, 5,
6, 8, 11, 12, 15, 16, and 19 seconds with a packet size of 4 bytes each. Assume that the
leaky bucket size X= 10 (queue size) bytes and the outgoing rate is one byte for every
second. Identify the conforming and nonconforming packets in the queue and display the
process on the screen.
2. Write a C program to avoid the congestion in network by using the Token bucket method.
Assume that we have a token bucket shaper that has a replenishment rate r = 10 KBps, an
infinite maximum rate R, a bucket size b = 50 Kbytes and that the bucket starts off full.
Also assume that a sender emits 15 Kbytes packet size every 0.5 seconds in a periodic manner, starting at t = 0.5 seconds. For this question, you can assume that if sufficient
tokens are available, packets pass through the token bucket instantaneously, otherwise
they are queued until there are.
    - How many tokens are left in the bucket after 1.5 seconds?
    - How long will it take until packets start to be queued or dropped?
    - Now, presume the sender can send as much as they want, whenever they want. If the
token bucket is changed to enforce a maximum rate R of 20 KBps, what would the
maximum possible burst size be?