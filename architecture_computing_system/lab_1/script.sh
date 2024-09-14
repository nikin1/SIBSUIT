#!/bin/bash

echo "OS"
hostnamectl | grep "Operating System"

echo ""
echo "KERNEL"
hostnamectl | grep "Kernel" | awk 'OFS=" " { print $1, $2, $3, $4}'
hostnamectl | grep "Architecture" | awk 'OFS=" " { print $1, $2, $3, $4}'

echo ""
echo "CPU"
cat /proc/cpuinfo | grep "model name" | head -1
lscpu | grep "CPU max MHz:" | awk 'OFS=" " { print $0}'
lscpu | grep "CPU min MHz:" | awk 'OFS=" " { print $0}'
cat /proc/cpuinfo | grep "cache size" | head -1

echo ""
echo "RAM"
free -h | awk '{print $1, $2, $3}' | head -1
free -h | grep Mem | awk '{print $2, $3, $4}'

echo ""
echo "IP/MAC"
interface_up=$(ip -br link show | awk '$2 == "UP" {print $1}' | head -1)
ip addr show $interface_up | grep link/ether | awk '{print $1, $2}'
ip addr show $interface_up | grep inet | awk '{print $1, $2}'

echo ""
df -h


