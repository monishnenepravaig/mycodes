clear all;
clc;
p=imread('umbrellas.jpg');
a=p;
[row col]=size(a);
for x=1:1:row
    for y=1:1:col
        if(p(x,y)<31)
            a(x,y)=p(x,y)/1.2;
        else
        if(p(x,y)>224)
            a(x,y)=p(x,y)/1.2;
            else
            a(x,y)=p(x,y)*1.2;
        end
        end
    end
end
subplot(1,2,1);
imshow(p);
title('Input Image');
subplot(1,2,2);
imshow(a);
title('contrast image');
