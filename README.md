# SPECIAL PONG
Bài tập cuối học phần INT2215
- Tên sinh viên: Nguyễn Mai Hiếu
- Mã sinh viên: 21020069
- Trường Đại học Công Nghệ- ĐHQG Hà Nội

## Mô tả chung về trò chơi

- Có 2 Level chơi: `dễ` và `khó` , có 2 chế độ chơi: `1 PLAYER` và `2 PLAYER`. 
 - Đối với dễ và chế độ 1 người chơi ta có map sân bóng và phải sử dụng `mũi tên lên,xuống` để điều khiển thanh để đỡ bóng , làm bóng bật ra, nếu k đỡ được bóng đối phương sẽ có 1 điểm. Còn chế độ 2 người chơi, người thứ nhất sẽ dùng phím `W` và `S` để di chuyển lên xuống thanh còn người thứ 2 dùng mũi tên lên xuống(lưu ý ở đây ta phải chuyển unikey về tiếng anh thì mới chơi được chế độ 2 người)
 - Đối với khó ta có map vũ trụ và các tiểu hành tinh là các chướng ngại vật, khi bóng (ở đây là các thiên thạch) đập vào chướng ngại vật thì bóng sẽ bị bật ra theo hướng khó đoán và tương tự với chế độ 1,2 người chơi
- Thang điểm ở đây là *5*, ai đạt *5* điểm trước thì người đó thắng

## Các chức năng đã cài đặt
- Menu game 
 - Chế độ 1, 2 người chơi và mức độ dễ và khó. Sau khi chọn xong mức độ, chế độ thì nút play hiện ra để bấm vào chơi
 - Chơi thua sẽ hiện ra GAME OVER, thắng sẽ hiện ra YOU WIN, người chơi 1 thắng sẽ hiện ra PLAYER 1 WIN và ngược lại
 - Menu khi kết thúc game gồm có REPLAY  để quay lại menu ban đầu và chơi tiếp, còn QUIT để thoát khỏi trò chơi
- Trong quá trình chơi muốn kết thúc giữa chừng sẽ phải bấm nút Esc hoặc bấm dấu x trên cửa sổ game. Sau đó bấm QUIT

## Các kiến thức đã sử dụng
- Con trỏ
- Class
- Vòng lặp while, if được sử dụng rất nhiều
- Tạo ra AI có tọa độ thay đổi theo tọa độ của quả bóng
- Nâng cao: Sử dụng các thư viện sau của **SDL2**( học cách cài đặt và code trên lazy foo) 
 - https://www.libsdl.org/download-2.0.php
 - https://www.libsdl.org/projects/SDL_image/
 - https://www.libsdl.org/projects/SDL_ttf/
 - https://www.libsdl.org/projects/SDL_mixer/

## Hướng dẫn cài đặt và vào được game
*Làm theo những hướng dẫn sau để setup thư viện vào Visual studio code:*
- http://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php
- http://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index.php
- SDL2_Mixer , SDL_Ttf cài đặt tương tự như SDL2_Image.
- ghi vào TERMINAL của VISUAL STUDIO CODE là:  binanddll/main.exe chương trình sẽ chạy được.

## Hướng phát triển
- Tạo thêm chế độ chơi 2 người nhưng 1 người là chuột, 1 người là bàn phím
- Tạo thêm các mức độ chơi, thêm các chướng ngại vật thú vị hơn như có một máy bắn ở giữa, ta phải vừa đỡ bóng, vừa phải né đạn từ máy không sẽ bị trừ mạng,...
- Tạo thêm nhiều chế độ chọn background của game, nhiều chế độ của quả bóng hơn.
## Nguồn tham khảo
- Em học và tham khảo trên https://www.youtube.com/watch?v=DeKfZhwyFO4&t=1715s 
- Âm thanh, hình ảnh e tự lấy trên mạng và tự chỉnh sửa 
## Điều tâm đắc rút ra được
- Chỉ tham khảo phần code logic của game pong truyền thống, còn lại là tự code, tự phát triển game
- Dùng được 4 thư viện hay sử dụng nhất của SDL2
- Biết tự cắt ghép chỉnh sửa ảnh để phù hợp với game
- Game: 
