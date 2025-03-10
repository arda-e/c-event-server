# C Event-Driven Web Server

A lightweight, high-performance HTTP server written in C, utilizing the `kqueue` event notification interface for efficient, non-blocking I/O operations.

---

## Overview

This project implements a modern event-driven web server in C, optimized for high performance and scalability. Instead of spawning threads for each connection, it leverages the `kqueue` event notification system to handle multiple concurrent connections with minimal overhead.

---

## Features

- **Event-driven architecture:** Uses `kqueue` for efficient event handling.
- **Non-blocking I/O:** Handles multiple connections without the overhead of threading.
- **HTTP protocol support:** Properly processes HTTP requests and responses.
- **Modular design:** Clearly separated components for socket handling, HTTP processing, and event management.
- **Lightweight:** Minimal external dependencies for better performance.

---

## Getting Started

### Prerequisites

- **C Compiler**: `gcc` or `clang`
- **CMake**: version 3.0 or higher
- **POSIX-compliant OS** with `kqueue` support (macOS, FreeBSD, etc.)

### Building

```bash
mkdir build
cd build
cmake ..
make
```

### Running the Server

```bash
./server
```

The server listens on port `8080` by default.

---

## Project Structure

```
project-root/
├── server.c                 # Main server implementation
├── server.utils.c           # Socket and server utility functions
├── server.utils.h           # Utility function declarations and configurations
├── events.c                 # Event handling with kqueue
├── events.h                 # Event handling declarations
└── http/
    ├── http_helpers.c       # HTTP request/response utilities
    ├── http_helpers.h       # HTTP helper function declarations
    ├── http_router.c        # URL routing and request handling
    └── http_router.h        # Router declarations
```

---