import re

if __name__ == '__main__':
    reg = re.compile('marshtomp', flags=re.I)
    while True:
        try:
            s = raw_input()
            print(reg.sub('fjxmlhx', s))
        except EOFError:
            break
            