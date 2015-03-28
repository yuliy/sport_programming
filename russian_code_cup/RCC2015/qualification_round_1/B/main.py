def main():
    t = int(input())
    for _ in xrange(0, t):
        x = int(input())
        y = int(input())
        z = int(input())
        if x*y == z:
            print('Infinity')
        else:
            print('Finite')

if __name__ == '__main__':
    main()
