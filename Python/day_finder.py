# enter date to get to know day of that date
def day_caluclator(d,m,y):
    if y>0:
        if m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12:
            if d>31:
                return 'invalid date'
        elif m==4 or m==6 or m==9 or m==11:
            if d>30:
                return 'invalid date'
        elif m==2:
            if y%4==0:
                if d>29:
                    return 'invalid date'
            else:
                if d>28:
                    return 'invalid date'
        else:
            return 'invalid date'
        if m==1:
            b=0
        elif m==2:
            b=31
        elif m==3:
            b=59
        elif m==4:
            b=90
        elif m==5:
            b=120
        elif m==6:
            b=151
        elif m==7:
            b=180
        elif m==8:
            b=212
        elif m==9:
            b=243
        elif m==10:
            b=273
        elif m==11:
            b=304
        elif m==12:
            b=334
        else:
            return 'invalid month'
        a=y
        a=a*365
        c=0
        for i in range(1,y):
            if i%4==0:
                c+=1
        a=a+b+c+d
        a=a%7
        if a==2:
            return 'sunday'
        elif a==3:
            return 'monday'
        elif a==4:
            return 'tuesday'
        elif a==5:
            return 'wednesday'
        elif a==6:
            return 'thursday'
        elif a==0:
            return 'friday'
        elif a==1:
            return 'saturday'
        return a 
