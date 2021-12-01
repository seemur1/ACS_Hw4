;------------------------------------------------------------------------------
; perimeter.asm - единица компиляции, вбирающая функции вычисления периметра
;------------------------------------------------------------------------------
extern FRACTION
extern POLAR
extern COMPLEX
extern numberSize
extern memcpy

;----------------------------------------------
; Вычисление значения дроби.
;double f_cast (void *me) {
;    return (double)(*((int*)(me))) / (double)(*((int*)(me + doubleSize)));
;}

global f_cast
f_cast:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес дроби
    cvtsi2sd xmm0, dword [rdi]
    cvtsi2sd xmm1, dword [rdi+8]
    divsd xmm0, xmm1

leave
ret

;----------------------------------------------
; Вычисление значения полярного числа
;double p_cast (void *me) {
;    return *((double*)(me));
;}
global p_cast
p_cast:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес полярного числа
    movsd xmm0, QWORD [rdi]

leave
ret

;----------------------------------------------
; Вычисление значения комплексного числа
;double c_cast (void *me) {
;    return sqrt(*((double*)(me)) * *((double*)(me)) + *((double*)(me + doubleSize)) * *((double*)(me + doubleSize)));
;}
global c_cast
c_cast:
section .text
    extern sqrt
push rbp
mov rbp, rsp

    ; В rdi адрес комплексного числа
    movsd xmm0, QWORD [rdi]
    mulsd xmm0, xmm0
    movsd xmm1, QWORD [rdi+4]
    mulsd xmm1, xmm1
    addsd xmm0, xmm1
    call sqrt

leave
ret

;----------------------------------------------
; Вычисление значения обобщённого числа.
;double n_cast(void *me) {
;    switch(*((int*)me)) {
;        case COMPLEX:
;            return c_cast(me + intSize);
;        case POLAR:
;            return p_cast(me + intSize);
;        default:
;            return f_cast(me + intSize);
;    }
;}
global n_cast
n_cast:
section .text
push rbp
mov rbp, rsp

    ; В rdi адрес фигуры
    mov eax, [rdi]
    cmp eax, [FRACTION]
    je .fCast
    cmp eax, [POLAR]
    je .pCast
    cmp eax, [COMPLEX]
    je .cCast
    xor eax, eax
    cvtsi2sd    xmm0, eax
    jmp     .return
.fCast:
    ; Вычисление периметра прямоугольника
    add     rdi, 4
    call    f_cast
    jmp     .return
.pCast:
    ; Вычисление периметра треугольника
    add     rdi, 4
    call    p_cast
    jmp     .return
.cCast:
    ; Вычисление периметра треугольника
    add     rdi, 4
    call    c_cast
.return:
leave
ret

; rdi - void *c
; rsi - void *item
; edx - l_border
; ecx - r_border
; return - eax
;----------------------------------------------
;int BinarySearch(void *c, void *item, int l_border, int r_border) {
;    if (r_border <= l_border) { return (n_cast(item) > n_cast(c + l_border * numberSize)) ? (l_border + 1) : l_border; }
;
;    int mid = (l_border + r_border) / 2;
;
;    if (n_cast(item) == n_cast(c + mid * numberSize)) { return mid + 1; }
;
;    if (n_cast(item) > n_cast(c + mid * numberSize)) { return BinarySearch(c, item, mid + 1, r_border); }
;    return BinarySearch(c, item, l_border, mid - 1);
;}

global BinarySearch
BinarySearch:
section .text
push    rbp
mov     rbp, rsp
        push    rbx
        sub     rsp, 56
        mov     qword [rbp-40], rdi
        mov     qword [rbp-48], rsi
        mov     dword [rbp-52], edx
        mov     dword [rbp-56], ecx
        mov     eax, ecx
        cmp     ecx, edx
        jg      .if2
        mov     rax, rsi
        mov     rdi, rax
        call    n_cast
        mov     ebx, eax
        mov     eax, [numberSize]
        imul    eax, edx
        movsx   rdx, eax
        mov     rax, qword [rbp-40]
        add     rax, rdx
        mov     rdi, rax
        call    n_cast
        mov     ecx, eax
        mov     eax, edx
        cmp     ebx, ecx
        jl      .add
        jmp     .return
.add:
        add     eax, 1
        jmp     .return
.if2:
        add     eax, edx
        mov     edx, eax
        shr     edx, 31
        add     eax, edx
        mov     edx, 0
        mov     ecx, 2
        div     ecx
        mov     dword [rbp-20], eax
        mov     rax, rsi
        mov     rdi, rax
        call    n_cast
        mov     ebx, eax
        mov     eax, dword [numberSize]
        imul    eax, dword [rbp-20]
        movsx   rdx, eax
        mov     rax, qword [rbp-40]
        add     rax, rdx
        mov     rdi, rax
        call    n_cast
        cmp     ebx, eax
        jne     .if3
        mov     eax, dword [rbp-20]
        add     eax, 1
        jmp     .return
.if3:
        mov     rax, qword [rbp-48]
        mov     rdi, rax
        call    n_cast
        mov     ebx, eax
        mov     eax, dword [numberSize]
        imul    eax, dword [rbp-20]
        movsx   rdx, eax
        mov     rax, qword [rbp-40]
        add     rax, rdx
        mov     rdi, rax
        call    n_cast
        mov     ecx, eax
        mov     eax, dword [rbp-20]
        cmp     ebx, ecx
        jge     .lower_middle
        lea     edi, [rax+1]
        mov     edx, dword [rbp-56]
        mov     rax, qword [rbp-40]
        mov     ecx, edx
        mov     edx, edi
        mov     rdi, rax
        call    BinarySearch
        jmp     .return
.lower_middle:
        lea     ecx, [rax-1]
        mov     edx, dword [rbp-52]
        mov     rax, qword [rbp-40]
        mov     rdi, rax
        call    BinarySearch
.return:
mov     rbx, qword [rbp-8]
leave
ret

global BinaryInsertion
BinaryInsertion:
section .text
        push    rbp
        mov     rbp, rsp
        sub     rsp, 64
        mov     qword [rbp-56], rdi
        mov     dword [rbp-60], esi
        lea     rax, [rbp-48]
        mov     qword [rbp-16], rax
        mov     dword [rbp-4], 1
        jmp     .end
.start:
        mov     eax, dword [rbp-4]
        sub     eax, 1
        mov     dword [rbp-8], eax
        mov     eax, [numberSize]
        movsx   rdx, eax
        mov     eax, [numberSize]
        imul    eax, dword [rbp-4]
        movsx   rcx, eax
        mov     rax, qword [rbp-56]
        add     rcx, rax
        lea     rax, [rbp-48]
        mov     rsi, rcx
        mov     rdi, rax
        call    memcpy
        mov     edx, dword [rbp-8]
        lea     rsi, [rbp-48]
        mov     rax, qword [rbp-56]
        mov     ecx, edx
        mov     edx, 0
        mov     rdi, rax
        call    BinarySearch
        mov     dword [rbp-20], eax
        mov     eax, dword [rbp-8]
        cmp     eax, dword [rbp-20]
        jge     .body
        mov     eax, [numberSize]
        movsx   rdx, eax
        mov     eax, dword [rbp-8]
        lea     ecx, [rax+1]
        mov     eax, [numberSize]
        imul    eax, ecx
        movsx   rcx, eax
        mov     rax, qword [rbp-56]
        add     rcx, rax
        lea     rax, [rbp-48]
        mov     rsi, rax
        mov     rdi, rcx
        call    memcpy
        add     dword [rbp-4], 1
        jmp     .end
.body:
        mov     eax, [numberSize]
        cdqe
        mov     edx, [numberSize]
        imul    edx, dword [rbp-8]
        movsx   rcx, edx
        mov     rdx, qword [rbp-56]
        lea     rsi, [rcx+rdx]
        mov     edx, dword [rbp-8]
        lea     ecx, [rdx+1]
        mov     edx, [numberSize]
        imul    edx, ecx
        movsx   rcx, edx
        mov     rdx, qword [rbp-56]
        add     rcx, rdx
        mov     rdx, rax
        mov     rdi, rcx
        call    memcpy
        sub     dword [rbp-8], 1
        mov     eax, dword [rbp-8]
        cmp     eax, dword [rbp-20]
        jge     .body
        mov     eax, [numberSize]
        movsx   rdx, eax
        mov     eax, dword [rbp-8]
        lea     ecx, [rax+1]
        mov     eax, [numberSize]
        imul    eax, ecx
        movsx   rcx, eax
        mov     rax, qword [rbp-56]
        add     rcx, rax
        lea     rax, [rbp-48]
        mov     rsi, rax
        mov     rdi, rcx
        call    memcpy
        add     dword [rbp-4], 1
.end:
        mov     eax, dword [rbp-4]
        cmp     eax, dword [rbp-60]
        jl      .start
        jmp     .return
.return:
        leave
        ret