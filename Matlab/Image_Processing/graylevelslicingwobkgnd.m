clear all;
a=imread('umbrellas.jpg');
p=a;
[row col]=size(a);
for x=1:1:row
    for y=1:1:col
        if(p(x,y)<97)
          p(x,y)=0;
            else
            if (p(x,y)>158)
                p(x,y)=0;
            else
            p(x,y)=255;
            end
        end
    end
end
subplot(1,2,1);
imshow(a);
title('Input image');
subplot(1,2,2);
colormap (gray);
imshow(p);
title('gray level slicing without background');