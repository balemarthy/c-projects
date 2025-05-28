# ByteFrame Protocol v0.1

Hey there 👋

If you're trying to learn how two microcontrollers can talk to each other using UART, you're in the right place.

This small project will help you:

- Learn how to send and receive messages over UART
- Build your own tiny protocol (yes, you!)
- Understand how to use function pointers
- Learn what a state machine is — without the confusion

Let’s go step by step. Simple, clean, and clear.

---

## 🚀 What Is ByteFrame?

ByteFrame is a very simple way to send and receive messages between two devices.

You wrap your data between two special bytes. You also do a trick called “escaping” if your data looks like those special bytes.

Why? So the receiver doesn’t get confused.

---

## 🔍 Packet Format

Here’s how the message looks:

| What        | Value  | What It Means             |
|-------------|--------|---------------------------|
| Start byte  | 0xC0   | Message is starting       |
| Data        | N bytes| Your real data            |
| End byte    | 0xC0   | Message is ending         |

But what if your real data has 0xC0 or 0xDB? No problem.

| If byte is  | Replace with     |
|-------------|------------------|
| 0xC0        | 0xDB 0xDC        |
| 0xDB        | 0xDB 0xDD        |

This way, your start and end bytes stay unique.

---

## 🛠 Files You’ll See

| File      | What It Does                          |
|-----------|----------------------------------------|
| `proto.h` | Holds important definitions            |
| `proto.c` | Logic for sending and receiving data   |
| `app.c`   | A small program to test it out         |
| `Makefile`| Helps you compile with one command     |

---

## 🧠 Two Big Concepts You’ll Learn

### 1. Function Pointers

In our send function, we don’t directly call UART functions.

Instead, we let **you** pass the function you want. This is the line:

## void send_packet(const uint8_t *data, int len, void (*tx)(uint8_t));

So you can do this in your code:

## send_packet(my_data, 5, uart_send_byte);

This means your UART code and protocol logic stay separate. You can test easily, and use this code on any board.

---

### 2. State Machine

When you receive data byte by byte, you need to remember what happened before.
You can't treat every byte the same.
So we use a state machine. Just 3 simple states:

IDLE: Waiting for the message to start
IN_FRAME: Message started, collect data
ESC: We got an escape character, handle it carefully


| State     | If we get… | Do this…              |
| --------- | ---------- | --------------------- |
| IDLE      | 0xC0       | Start collecting data |
| IN\_FRAME | Normal     | Add it to buffer      |
| IN\_FRAME | 0xDB       | Go to ESC state       |
| IN\_FRAME | 0xC0       | End of message        |
| ESC       | 0xDC/0xDD  | Convert to 0xC0/0xDB  |
| ESC       | Anything   | Just store it         |

This is the heart of many protocols. Once you get this, you’ll be able to understand bigger systems too.

---

🧪 How To Run It (On Your PC)
make
./app

It sends a sample message and shows what was received.

# Want to run it on real hardware? Just replace the tx() function with your UART send function.

✅ What You Can Do Next
Add checksum (CRC8) to check if message got corrupted
Add a command byte to say what the message means
Use ring buffers for smooth message handling
Use in FreeRTOS or your main loop

This is your protocol. Take it. Play with it. Break it. Fix it. Make it yours.

If you found this useful, drop a ⭐ on the repo. Or better, try adding a new feature and tag me!

Happy coding!
