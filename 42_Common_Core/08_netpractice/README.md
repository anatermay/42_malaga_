# NetPractice

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Networking](https://img.shields.io/badge/Subject-Networking-brightgreen)
![Rank](https://img.shields.io/badge/Rank-04-orange)
![Score](https://img.shields.io/badge/Score-100%2F100-success)

## 📋 Project Overview

`NetPractice` is a practical networking exercise that teaches the fundamentals of network configuration, IP addressing, and routing. This project is part of the 42 Common Core curriculum (Rank 04) and focuses on understanding TCP/IP networking concepts through hands-on configuration exercises.

## 🎯 Objectives

- Understand TCP/IP protocol stack fundamentals
- Master IP addressing and subnet mask calculations
- Learn network routing and gateway configuration
- Practice CIDR notation and subnetting techniques
- Configure network interfaces and routing tables
- Troubleshoot network connectivity issues
- Apply OSI model concepts in practical scenarios

## 🌐 Networking Concepts Covered

### Core Networking Fundamentals
| Concept | Description | Application |
|---------|-------------|-------------|
| **IP Addressing** | IPv4 address structure and classes | Interface configuration |
| **Subnet Masks** | Network and host identification | Network segmentation |
| **CIDR Notation** | Classless Inter-Domain Routing | Efficient address allocation |
| **Default Gateway** | Router interface for external traffic | Inter-network communication |
| **Routing Tables** | Path determination for packet forwarding | Network traffic direction |
| **Network Interfaces** | Physical/logical network connections | Device connectivity |

### Advanced Topics
- **Subnetting**: Dividing networks into smaller segments
- **VLSM**: Variable Length Subnet Masking
- **Route Aggregation**: Combining multiple routes
- **Network Troubleshooting**: Connectivity problem solving

## 📁 Project Structure

```
8_netpractice/
├── level1.json                     # Basic IP addressing
├── level2.json                     # Subnet mask introduction
├── level3.json                     # Simple routing
├── level4.json                     # Multiple interfaces
├── level5.json                     # Gateway configuration
├── level6.json                     # Complex subnetting
├── level7.json                     # CIDR and routing
├── level8.json                     # Advanced routing scenarios
├── level9.json                     # Multi-router networks
├── level10.json                    # Complex network topology
└── README.md                       # This file
```

## 🚀 Level Progression

### **Level 1-3: Fundamentals**
- Basic IP address assignment
- Introduction to subnet masks
- Simple point-to-point connections
- Understanding network and broadcast addresses

### **Level 4-6: Intermediate Concepts**
- Multiple network interfaces
- Gateway configuration
- Subnet mask calculations
- Network segmentation

### **Level 7-10: Advanced Scenarios**
- Complex routing tables
- Multi-router topologies
- CIDR notation mastery
- Real-world network simulation

## 💡 Key Learning Outcomes

### IP Addressing Mastery
- **IPv4 Structure**: Understanding 32-bit addressing
- **Address Classes**: Class A, B, and C networks
- **Private vs Public**: RFC 1918 private address ranges
- **Network vs Host**: Subnet mask role in address division

### Subnetting Excellence
- **CIDR Calculations**: Converting between decimal and CIDR
- **Subnet Planning**: Efficient network design
- **VLSM Implementation**: Variable subnet sizes
- **Address Conservation**: Optimal IP allocation

### Routing Understanding
- **Default Routes**: 0.0.0.0/0 gateway configuration
- **Static Routing**: Manual route table entries
- **Route Specificity**: Longest prefix matching
- **Multi-hop Routing**: Path through multiple routers

## 🧪 Example Configurations

### Basic Network Setup
```json
{
  "ifs": {
    "A1": {"ip": "192.168.1.1", "mask": "255.255.255.0"},
    "B1": {"ip": "192.168.1.2", "mask": "255.255.255.0"}
  },
  "routes": {}
}
```

### Gateway Configuration
```json
{
  "ifs": {
    "A1": {"ip": "10.0.0.1", "mask": "255.255.255.0"},
    "R1": {"ip": "10.0.0.254", "mask": "255.255.255.0"}
  },
  "routes": {
    "Ar1": {"route": "default", "gate": "10.0.0.254"}
  }
}
```

### Complex Routing
```json
{
  "routes": {
    "H3r1": {"gate": "139.111.59.195"},
    "R1r1": {"route": "139.111.59.192/26"},
    "Ir1": {"route": "139.111.59.0/24"}
  }
}
```

## 🔧 Technical Skills Developed

### Network Configuration
- **Interface Setup**: IP and mask assignment
- **Route Management**: Static route configuration
- **Gateway Assignment**: Default route setup
- **Network Validation**: Connectivity verification

### Addressing Schemes
- **Subnet Design**: Efficient network planning
- **CIDR Mastery**: Classless addressing
- **Address Calculation**: Network math proficiency
- **Conflict Resolution**: Overlapping network prevention

### Troubleshooting
- **Connectivity Issues**: Network reachability problems
- **Routing Problems**: Path determination errors
- **Configuration Errors**: Syntax and logic mistakes
- **Network Isolation**: Segmentation issues

## 📊 Practical Applications

### Enterprise Networks
- **Office LANs**: Local area network design
- **Branch Connectivity**: WAN connection setup
- **VLAN Configuration**: Virtual network segmentation
- **Security Zones**: Network isolation strategies

### Service Provider Networks
- **Customer Networks**: ISP subnet allocation
- **BGP Routing**: Internet routing protocols
- **Traffic Engineering**: Optimal path selection
- **Network Scaling**: Growth accommodation

### Cloud Infrastructure
- **VPC Design**: Virtual private clouds
- **Subnet Allocation**: Resource segmentation
- **Route Tables**: Traffic control
- **Network ACLs**: Security rule implementation

## 🌟 Key Achievements

### Network Design Proficiency
✅ **Subnet Calculation Mastery**: Instant CIDR to decimal conversion  
✅ **Routing Table Configuration**: Complex multi-hop scenarios  
✅ **Network Troubleshooting**: Rapid problem identification  
✅ **Address Planning**: Efficient IP allocation strategies  

### Protocol Understanding
✅ **TCP/IP Stack**: Layer interaction comprehension  
✅ **OSI Model**: Practical application of networking layers  
✅ **Packet Flow**: End-to-end communication understanding  
✅ **Network Security**: Basic security principle application  

## 🔗 Real-World Relevance

### Career Applications
- **Network Engineering**: Infrastructure design and management
- **Systems Administration**: Server network configuration
- **Cloud Architecture**: Virtual network design
- **DevOps**: Container networking and service mesh
- **Cybersecurity**: Network security and monitoring

### Industry Standards
- **RFC Compliance**: Internet standard adherence
- **Best Practices**: Industry-standard configurations
- **Scalability**: Enterprise-grade network design
- **Documentation**: Network topology documentation

## 🎓 Skills Acquired

### Technical Competencies
- **Network Design**: End-to-end network architecture
- **IP Planning**: Structured address allocation
- **Routing Protocols**: Static and dynamic routing
- **Network Segmentation**: Security and performance optimization

### Problem-Solving Abilities
- **Analytical Thinking**: Systematic problem breakdown
- **Pattern Recognition**: Common network issues identification
- **Configuration Management**: Structured approach to setup
- **Documentation Skills**: Clear network documentation

## 🔗 Links

- **Author**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **42 Profile**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repository**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 📊 42 Common Core Progress

This project is part of my journey through the 42 Common Core curriculum:

- **Rank 00**: ✅ libft
- **Rank 01**: ✅ ft_printf, born2beroot, get_next_line
- **Rank 02**: ✅ push_swap, examrank02, so_long, minitalk
- **Rank 03**: ✅ philosophers, examrank03, minishell
- **Rank 04**: 🔄 netpractice (done), examrank04, cub3d, CPP 00-04

## 🏆 Achievement

**Final Score**: 100/100 ✨

---

*This project was completed as part of the 42 School curriculum at 42 Málaga.*
