#### Dynamic Network Service Manager for Linux (`dnsman`)

**Goal**: Develop a lightweight, containerized network service manager that integrates with `systemd`, dynamically handles IP assignments, manages sockets efficiently, and exposes network performance metrics via Prometheus. The project aims to provide a flexible, high-performance network management tool suitable for could environments and high-performance computing clusters. 

**Task Description**: Develop a **daemon (`dnsman`)** that runs as a `systemd` service and manages network interfaces and sockets dynamically. The daemon should:
1. **Monitor and configure network interfaces**
    - Detect active interfaces (`eth0`, `wlan0`, `lo`, etc.)
    - Assign IP addresses (DHCP/static configuration via Netlink)
    - React to interface changes (e.g., new interfaces, disconnections)
2. **Manage sockets efficiently**
    - Open, bind, and manage TCP/UDP sockets
    - Monitor active connections and report statistics
    - Implement basic connection prioritization (e.g., keep-alive for critical services)
3. **Integrate with `systemd`**
    - Run as a `systemd` service
    - Use `systemd` socket activation (lazy start of network services)
    - Log events via `journald`
4. **Expose Prometheus metrics**
    - Track **active connections, dropped packets, and bandwidth usage**
    - Provide an HTTP endpoint (`/metrics`) for Prometheus scraping
5. **Provide a minimal CLI (`dnsmanctl`)**
    - Start/stop the daemon
    - List active interfaces and sockets
    - Manually configure IP addresses
