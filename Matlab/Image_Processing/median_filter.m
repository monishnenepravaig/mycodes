clear all;
clc;
p=imread('umbrellas.jpg');
subplot(1,2,1);
imshow(p);
title('Input Image');
a=p;
[row col]=size(a);
for x=2:1:row-1
    for y=2:1:col-1
        A=[p(x-1,y-1),p(x,y-1),p(x+1,y-1),p(x-1,y),p(x,y),p(x+1,y),p(x-1,y+1),p(x,y+1),p(x+1,y+1)];
        B=sort(A);
        a(x,y)=B(5);
    end
end
subplot(1,2,1);
title('Input Image');
subplot(1,2,2);
imshow(a);
title('Median Filter Image');