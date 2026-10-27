#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Size of TX and RX buffers
#define UART_BUFFER_SIZE 64

// Circular Queue Structure
typedef struct
{
    uint8_t buffer[UART_BUFFER_SIZE];
    int head;
    int tail;
    int count;
} UART_BUFFER;

// UART Simulation Structure
typedef struct
{
    UART_BUFFER txBuffer;
    UART_BUFFER rxBuffer;
} UART_Device;

// Queue Functions
void UART_BUFFER_INIT(UART_BUFFER *buf)
{
    buf->head = 0;
    buf->tail = 0;
    buf->count = 0;
}

bool UART_BUFFER_IsFull(UART_BUFFER *buf)
{
    return buf->count == UART_BUFFER_SIZE;
}

bool UART_BUFFER_IsEmpty(UART_BUFFER *buf)
{
    return buf->count == 0;
}

bool UART_BUFFER_Enqueue(UART_BUFFER *buf, uint8_t data)
{
    if (UART_BUFFER_IsFull(buf))
        return false;
    buf->buffer[buf->head] = data;
    buf->head = (buf->head + 1) % UART_BUFFER_SIZE;
    buf->count++;
    return true;
}

bool UART_BUFFER_Dequeue(UART_BUFFER *buf, uint8_t *data)
{
    if (UART_BUFFER_IsEmpty(buf))
        return false;
    *data = buf->buffer[buf->tail];
    buf->tail = (buf->tail + 1) % UART_BUFFER_SIZE;
    buf->count--;
    return true;
}

// UART Functions
void UART_INIT(UART_Device *uart)
{
    UART_BUFFER_INIT(&uart->txBuffer);
    UART_BUFFER_INIT(&uart->rxBuffer);
    printf("UART Initialized.\n");
}

// Simulate Sending A Byte Over UART
void UART_SendByte(UART_Device *uart, uint8_t data)
{
    if (UART_BUFFER_Enqueue(&uart->txBuffer, data))
        printf("TX: '%c' enqueued\n", data);
    else
        printf("TX Buffer Full! Data lost.\n");
}

// Simulate Receiving A Byte From UART Hardware
void UART_ReceiveByte(UART_Device *uart, uint8_t data)
{
    if (UART_BUFFER_Enqueue(&uart->rxBuffer, data))

        printf("RX: '%c' received\n", data);
    else
        printf("RX Buffer Full! Data lost.\n");
}

// Simulate UART Transmitting Data (sending from TX buffer)
void UART_ProcessTransmit(UART_Device *uart)
{
    uint8_t data;
    while (UART_BUFFER_Dequeue(&uart->txBuffer, &data))
    {
        printf("Transmitted: '%c'\n", data);
    }
}

// Simulate UART Reading Data (from RX buffer)
void UART_ReadReceivedData(UART_Device *uart)
{
    uint8_t data;
    while (UART_BUFFER_Dequeue(&uart->rxBuffer, &data))
    {
        printf("Read from RX: '%c'\n", data);
    }
}

int main()
{
    UART_Device uart;
    UART_INIT(&uart);

    // Simulate Sending Data
    UART_SendByte(&uart, 'W');
    UART_SendByte(&uart, 'R');
    UART_SendByte(&uart, 'O');
    UART_SendByte(&uart, 'L');
    UART_SendByte(&uart, 'D');
    printf("\n");

    // Process TX (Simulate Actual Transmission)
    UART_ProcessTransmit(&uart);
    printf("\n");

    // Simulate Receiving Data
    UART_ReceiveByte(&uart, 'O');

    UART_ReceiveByte(&uart, 'K');
    printf("\n");

    // Process RX (Read Incoming Data)
    UART_ReadReceivedData(&uart);

    return 0;
}
