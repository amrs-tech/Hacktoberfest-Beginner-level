import random
import sys

SYMBOLS = 'QWERTYUIOPASDFGHJKLÇZXCVBNM'
SYMBOLS += SYMBOLS.lower() + '0123456789'
S_length = len(SYMBOLS)


def main():
    my_key = get_rand_key()
    my_text = 'A computer would deserve to be called intelligent if it could deceive a human into believing that it ' \
              'was human'

    cipher = encrypt_message(my_key, my_text)
    print('key: ', my_key)
    print('cipher: ', cipher)


def get_rand_key():
    while True:
        n_1 = random.randint(2, S_length)
        n_2 = random.randint(2, S_length)
        print('n1: ', n_1, 'n2: ', n_2)
        if common_div(n_1, S_length) == 1:
            return n_1 * S_length + n_2


def common_div(a, b):
    while a != 0:
        a, b = b % a, a
    return b


def split_key(key):
    key_a = key // S_length
    # print('key_a', key_a)
    key_b = key % S_length
    # print('key_b', key_b)
    return key_a, key_b


def key_check(key_a, key_b):
    if key_a == 1:
        sys.exit('cipher is weak if key_a == 1')
    if key_b == 0:
        sys.exit('cipher is weak is key_b = 0')
    if key_a < 0 or key_b < 0 or key_b > S_length - 1:
        sys.exit()
    if common_div(key_a, S_length - 1) != 1:
        sys.exit('key_a and SYMBOLS s size are not coprime')


def encrypt_message(key, message):
    key_a, key_b = split_key(key)
    key_check(key_a, key_b)
    cipher = ''

    for letter in message:
        if letter in SYMBOLS:
            letter_index = SYMBOLS.find(letter)

            cipher += SYMBOLS[(letter_index * key_a + key_b) % S_length]

        else:
            cipher += letter
    return cipher


if __name__=='__main__':
    main()
