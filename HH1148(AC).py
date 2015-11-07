import re

def isLeap(x):
    return  x % 400 == 0 if x % 100 == 0 else x % 4 == 0

def nlpy(y):
    y = y / 4 * 4 + 4
    while not isLeap(y):
        y += 4
    return y
    
def nextLeap(t):
    y = t[0]
    if not isLeap(y):
        return (nlpy(y), 2, 29)
    elif t <= (y, 2, 29):
        return (y, 2, 29)
    else:
        return (nlpy(y), 2, 29)
        
def parse(s, mdict):
    mm, dd, yy = re.split('\s+', re.sub(',', '', s))
    yy = int(yy)
    mm = mdict[mm]
    dd = int(dd)
    return (yy, mm, dd)
    
def next(y, d):
    return y if y % d == 0 else y / d * d + d
    
def countYear(y1, y2):
    c4 = (y2 - y1) / 4
    c100 = (next(y2, 100) - next(y1, 100)) / 100
    c400 = (next(y2, 400) - next(y1, 400)) / 400
    return c4 - c100 + c400
    
if __name__ == '__main__':
    months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"]
    mdict = {}
    for i in xrange(12):
        mdict[months[i]] = i + 1;
    cn = int(raw_input().strip())
    for ci in xrange(cn):
        t1 = parse(raw_input().strip(), mdict)
        t2 = parse(raw_input().strip(), mdict)
        t2 = (t2[0], t2[1], t2[2] + 1)
        t1 = nextLeap(t1)
        t2 = nextLeap(t2)
        print('Case #%d: %d' % (ci + 1, countYear(t1[0], t2[0])))
        