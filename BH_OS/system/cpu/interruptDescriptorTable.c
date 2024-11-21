#include <stdint.h>
#include <interruptDescriptorTable.h>
__attribute__((aligned(0x10)))
static idt_entry_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void set_idt_gate(int n, uint32_t handler) {
    idt[n].isr_low = LOW_16(handler);
    idt[n].kernel_cs = KERNEL_CS;
    idt[n].reserved = 0;
    idt[n].attributes = 0x8E;
    idt[n].isr_high = HIGH_16(handler);
}

void set_idt() {
    idt_reg.base = (uint32_t) &idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_entry_t) - 1;
    asm volatile("lidt (%0)" : : "r" (&idt_reg));
}