clear all;
clc;
p=imread('umbrellas.jpg');
a=p;
[row col]=size(a);
for x=1:1:row
    for y=1:1:col
        if(p(x,y)<127)
            a(x,y)=0;
        else
            a(x,y)=255;
        end
    end
end
subplot(1,2,1);
imshow(p);
title('Input Image');
subplot(1,2,2);
imshow(a);
title('Threshold image');