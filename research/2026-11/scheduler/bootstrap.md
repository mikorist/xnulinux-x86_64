# Scheduler and Mach IPC bootstrap

**Date:** 2026-11-25  
**Scope:** Standalone uniprocessor kernel.

Initial processor and thread bootstrap established the active thread and processor set. A large debugger memory read failed in the verifier; bounded reads corrected the measurement without changing the guest.

The subsequent research recorded scheduler initialization, Mach IPC startup, kernel task and thread initialization, the first kernel context, idle thread creation and a two-thread scheduler round trip. A Legacy interrupt handoff problem was corrected before the round trip.

A naturally delivered LAPIC timer interrupt subsequently entered the registered clock handler and returned to the original execution context. Interrupt and preemption levels returned to their previous values. The verifier did not inject the interrupt.

## Limits

Mach IPC startup is not proof of user-space message exchange or port-right lifetime correctness. The timer test is not proof of timer-driven scheduling, NMI safety, SMP or user-mode return. Hosted CPU state transitions require separate tests.

**Source records:** checkpoints 91–92 and 104–112; summary of recorded boundaries.
