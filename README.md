# pthread_rwlock
三个线程写，5个线程读

效果：
---1th-----num: 0 after write: num is 1

=======1th==========num is 1

=======5th==========num is 1

=======2th==========num is 1

=======3th==========num is 1

=======4th==========num is 1

---2th-----num: 1 after write: num is 2

---3th-----num: 2 after write: num is 3

---1th-----num: 3 after write: num is 4

---2th-----num: 4 after write: num is 5

---3th-----num: 5 after write: num is 6

=======1th==========num is 6

=======2th==========num is 6

=======3th==========num is 6

=======4th==========num is 6

=======5th==========num is 6

---1th-----num: 6 after write: num is 7

---2th-----num: 7 after write: num is 8

---3th-----num: 8 after write: num is 9

---1th-----num: 9 after write: num is 10

---2th-----num: 10 after write: num is 11

---3th-----num: 11 after write: num is 12

=======5th==========num is 12

=======1th==========num is 12

=======2th==========num is 12

=======3th==========num is 12

=======4th==========num is 12

---1th-----num: 12 after write: num is 13

---2th-----num: 13 after write: num is 14

---3th-----num: 14 after write: num is 15

---1th-----num: 15 after write: num is 16

---2th-----num: 16 after write: num is 17

---3th-----num: 17 after write: num is 18

=======1th==========num is 18

=======5th==========num is 18

=======2th==========num is 18

=======3th==========num is 18

=======4th==========num is 18

---1th-----num: 18 after write: num is 19

---2th-----num: 19 after write: num is 20

---3th-----num: 20 after write: num is 21

---1th-----num: 21 after write: num is 22

---2th-----num: 22 after write: num is 23

---3th-----num: 23 after write: num is 24

=======2th==========num is 24

=======4th==========num is 24

=======1th==========num is 24

=======3th==========num is 24

=======5th==========num is 24

---1th-----num: 24 after write: num is 25

^C
