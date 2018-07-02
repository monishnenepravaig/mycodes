clear all;
clc;
p=imread('umbrellas.jpg');
a=p;
[row col]=size(a);
for x=1:1:row
    for y=1:1:col
        r = a(x,y);
        e=r+1;
        k = (e-1)-(0.5*power((e-1),2))+(0.3333*power((e-1),3))-((0.25)*power((e-1),4))+((1/5)*power((e-1),5))-((1/6)*power((e-1),6))+((1/7)*power((e-1),7))-((1/8)*power((e-1),8))+((1/9)*power((e-1),9))-((1/10)*power((e-1),10));
       p(x,y)= 1.2*k;    
    end
end
subplot(1,2,1);
imshow(a);
title('Input Image');
subplot(1,2,2);
imshow(p);
title('dynamic range compression image');