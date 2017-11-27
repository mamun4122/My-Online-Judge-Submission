n = input();
st = input();
l = len(st);
st = st + '#';
prev = '#';
res = "";
aa=0;
ee=0;
ii=0;
oo=0;
uu=0;
yy=0;
for now in st:
  if(now!=prev):
    if aa>0:
      res += 'a';
    if ee==2:
      res += "ee";
    elif ee>0:
      res += 'e';
    if ii>0:
      res += 'i';
    if oo==2:
      res += "oo";
    elif oo>0:
      res += 'o';
    if uu>0:
      res += 'u';
    if yy>0:
      res += 'y';
    aa=0;
    ee=0;
    ii=0;
    oo=0;
    uu=0;
    yy=0;
  if now == 'a':
    ee=0;
    ii=0;
    oo=0;
    uu=0;
    yy=0;
    aa=aa+1;
  elif now == 'e':
    aa=0;
    ii=0;
    oo=0;
    uu=0;
    yy=0;
    ee=ee+1;
  
  
  elif now == 'i':
    aa=0;
    ee=0;
    oo=0;
    uu=0;
    yy=0;
    ii = ii + 1;
  
  elif now == 'o':
    aa=0;
    ee=0;
    ii=0;
    uu=0;
    yy=0;
    oo = oo + 1;
  
  elif now == 'u':
    aa=0;
    ee=0;
    ii=0;
    oo=0;
    yy=0;
    uu = uu+1;
  
  elif now == 'y':
    aa=0;
    ee=0;
    ii=0;
    oo=0;
    uu=0;
    yy = yy+1;
    
  elif now != '#':
    res += now;
    
  prev = now;
  
  
print(res);