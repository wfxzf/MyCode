from PIL import Image
import os

def rea(pdf_name):
    file_list = os.listdir('image')
    pic_name = []
    im_list = []
    for x in file_list:
        if "jpg" in x or 'png' in x or 'jpeg' in x:
            pic_name.append(x)
    pic_name.sort()
    new_pic = []
    for x in pic_name:
        if "jpg" in x:
            new_pic.append(x)
    for x in pic_name:
        if "png" in x:
            new_pic.append(x)
    im1 = Image.open('image/'+new_pic[0])
    new_pic.pop(0)
    for i in new_pic:
        img = Image.open('image/'+i)
        img = img.convert('RGB')
        im_list.append(img)
    
    print(len(im_list))
  
    im1.save(pdf_name, "PDF", resolution=200.0, save_all=True, append_images=im_list)
    print("输出文件名称：", pdf_name)

if __name__ == '__main__':
  print("合成")
  pdf_name = input("请输入合成PDF文件名称：")
  if ".pdf" in pdf_name:
    rea(pdf_name=pdf_name)
  else:
    rea(pdf_name="{}.pdf".format(pdf_name))
  input("按任意键结束")