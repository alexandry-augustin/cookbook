import numpy as np
from PIL import Image

if __name__ == '__main__':

    # from image
    path = '../../../../res/lena.bmp'
    img = Image.open(path)

    img.show()
    # img.save("out.jpg")

    # from array (monochromatic)
    colour = 255
    data = np.eye(200)*colour
    data = data.astype('uint8')
    img = Image.fromarray(data)
    img = img.convert('RGB')

    img.show()

    # from array (RGB)
    # colour = np.array([125, 255, 0])
    # data = np.eye(200) # TODO
    # data = data.astype('uint8')
    # img = Image.fromarray(data)

    # img.show()
