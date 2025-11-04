# minitalk

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Language](https://img.shields.io/badge/Language-C-brightgreen)
![Rank](https://img.shields.io/badge/Rank-02-orange)
![Score](https://img.shields.io/badge/Score-121%2F100-success)

## 📋 Project Description

`minitalk` is a communication program between client and server using UNIX signals. This project is part of the 42 School Common Core curriculum (Rank 02) and focuses on understanding inter-process communication, signal handling, and bit manipulation in C programming.

## 🎯 Objectives

- Implement a client-server communication system using only UNIX signals
- Handle `SIGUSR1` and `SIGUSR2` signals for binary data transmission
- Convert characters to binary and transmit bit by bit
- Ensure reliable message delivery and error handling
- Create a bonus version with acknowledgment system
- Follow 42 School coding standards (Norminette)

## 🔧 Signal Communication

The program uses two UNIX signals for communication:

| Signal | Binary Value | Description |
|--------|--------------|-------------|
| `SIGUSR1` | 0 | Represents binary bit 0 |
| `SIGUSR2` | 1 | Represents binary bit 1 |

### Communication Flow
1. **Server** starts and displays its Process ID (PID)
2. **Client** takes server PID and message as arguments
3. **Client** converts each character to 8-bit binary
4. **Client** sends each bit using `SIGUSR1` (0) or `SIGUSR2` (1)
5. **Server** reconstructs the message bit by bit
6. **Server** displays the complete message

## 📁 Project Structure

```
4_minitalk/
├── server.c              # Server implementation
├── client.c              # Client implementation
├── server_bonus.c        # Server with acknowledgment (bonus)
├── client_bonus.c        # Client with acknowledgment (bonus)
├── minitalk.h            # Header file for mandatory part
├── minitalk_bonus.h      # Header file for bonus part
├── Makefile             # Build configuration
└── README.md            # This file
```

## 🚀 Usage

### Compilation

```bash
# Compile mandatory version
make

# Compile bonus version
make bonus

# Clean object files
make clean

# Clean everything
make fclean

# Recompile everything
make re
```

### Running the Program

#### Mandatory Version

```bash
# Terminal 1: Start the server
./server
# Output: Server PID: [number]

# Terminal 2: Send a message
./client [server_pid] "Hello, World!"
```

#### Bonus Version

```bash
# Terminal 1: Start the bonus server
./server_bonus
# Output: Server PID: [number]

# Terminal 2: Send a message with acknowledgment
./client_bonus [server_pid] "Hello, World!"
# Output: Message sent successfully!
```

### Examples

```bash
# Basic communication
./server &
./client 12345 "42 School is awesome!"

# Unicode support (bonus)
./server_bonus &
./client_bonus 12345 "Hello 🌍!"

# Multiple messages
./server &
./client 12345 "First message"
./client 12345 "Second message"
```

## 💡 Technical Implementation

### Bit Manipulation
- Each character is converted to its 8-bit binary representation
- Bits are sent from least significant bit (LSB) to most significant bit (MSB)
- Server reconstructs characters by accumulating received bits

### Signal Handling
```c
// Server signal handler
void server_receptor(int sig, siginfo_t *info, void *context)
{
    static unsigned char val = 0;
    static int bit = 1;
    
    if (sig == SIGUSR1)
        val += 0;      // Binary 0
    if (sig == SIGUSR2)
        val += bit;    // Binary 1
    
    bit <<= 1;         // Move to next bit position
    
    if (bit == 256)    // Complete byte received
    {
        write(1, &val, 1);  // Output character
        val = 0;            // Reset for next character
        bit = 1;            // Reset bit position
    }
}
```

### Error Handling
- Validates command line arguments
- Handles signal transmission failures
- Manages invalid PIDs
- Implements timeout mechanisms (bonus)

## 🏆 Bonus Features

The bonus implementation includes additional features:

### Server Acknowledgment
- Server sends confirmation signal back to client
- Client waits for acknowledgment before sending next bit
- Ensures reliable message delivery

### Unicode Support
- Handles multi-byte UTF-8 characters
- Supports emojis and special characters
- Maintains proper encoding throughout transmission

### Enhanced Error Handling
- Comprehensive error messages
- Graceful failure recovery
- Robust signal handling

## 🧪 Testing

The project handles various scenarios:
- Single character messages
- Long text messages
- Empty messages
- Special characters and Unicode
- Multiple consecutive messages
- Invalid PIDs and arguments
- Signal transmission failures

### Performance Considerations
- Efficient bit-by-bit transmission
- Minimal memory usage
- Fast signal processing
- Low latency communication

## 📈 Technical Challenges

### Signal Reliability
- UNIX signals are not queued by default
- Risk of signal loss during rapid transmission
- Solution: Implemented acknowledgment system in bonus

### Bit Order Management
- Consistent bit ordering between client and server
- Proper byte reconstruction from individual bits
- Handling of multi-byte characters

### Process Synchronization
- Coordinating client sending rate with server processing
- Preventing signal overflow
- Managing concurrent clients (bonus consideration)

## 🔗 Links

- **Author**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **42 Profile**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repository**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 🏆 Achievement

**Final Score**: 121/100 ✨

---

*This project was completed as part of the 42 School curriculum at 42 Málaga.*
