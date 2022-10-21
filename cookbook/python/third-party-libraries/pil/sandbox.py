import numpy as np
from PIL import Image

if __name__ == '__main__':

    # from image
    path = '../../../../res/lena.bmp'
    img = Image.open(path)

    img.show()
    # img.save("out.jpg")

    # from array
    data = (np.eye(200)*255).astype('uint8') # sample array
    im = Image.fromarray(data) # monochromatic image
    imrgb = im.convert('RGB') # color image

    imrgb.show()
