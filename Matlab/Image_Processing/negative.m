clear all;
a=imread('umbrellas.jpg');
p=a;
[row col]=size(a);
for x=1:1:row
    for y=1:1:col
    p(x,y)=255-a(x,y);    
    end
end
subplot(1,2,1);
imshow(a);
title('Input image');
subplot(1,2,2);
colormap (gray);
imshow(p);
title('Image inverse');