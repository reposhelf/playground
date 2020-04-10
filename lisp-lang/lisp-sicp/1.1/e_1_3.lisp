#!/usr/local/bin/guile -s
!#
; Exercise 1.3.
; Define a procudeure that takes three numbers
; as arguments and returns the sum of the squares
; of the two larger numbers.

; Returns the square of 'x'
(define (square x) (* x x))

; Returns sum of squares of two numbers
(define (sum-squares a b)
  (+ (square a) (square b)))

; Helper procedure '<='
(define (<= a b) (not (> a b)))

; Main procedure. Takes three numbers
(define (sum-squares-largers a b c)
  (cond ((and (<= a b) (<= a c)) (sum-squares b c))
        ((and (<= b a) (<= b c)) (sum-squares a c))
        (else (sum-squares a b))))

; Check.

; 2
(display (sum-squares-largers 1 1 1))
(newline)

; 5
(display (sum-squares-largers 1 1 2))
(newline)

; 5
(display (sum-squares-largers 1 2 1))
(newline)

; 5
(display (sum-squares-largers 2 1 1))
(newline)

; 8
(display (sum-squares-largers 2 2 1))
(newline)

; 8
(display (sum-squares-largers 2 1 2))
(newline)

; 8
(display (sum-squares-largers 1 2 2))
(newline)

; 13
(display (sum-squares-largers 1 2 3))
(newline)

; 13
(display (sum-squares-largers 1 3 2))
(newline)

; 13
(display (sum-squares-largers 3 1 2))
(newline)

; 13
(display (sum-squares-largers 3 2 1))
(newline)

; 13
(display (sum-squares-largers 2 3 1))
(newline)

; 13
(display (sum-squares-largers 2 1 3))
(newline)

; 10
(display (sum-squares-largers -2 1 3))
(newline)

; 10
(display (sum-squares-largers 2 1 -3))
(newline)
