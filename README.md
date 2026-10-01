# Pico String
Một thư viện được viết bằng C để xử lý chuỗi trên các nền tảng có tài nguyên hạn chế .
## Phụ thuộc 
Tối thiểu 1 trình biên dịch C ( tối thiểu chuẩn C99 )
## Hướng dẫn
Có lẽ cách tốt nhất vẫn là đi đọc Header
## Biên dịch
Có thể sử dụng qua script `mak` trong thư mục test để biên dịch tùy theo nhu cầu .
### biên dịch OBJ
Tùy chọn này tạo ra 1 tệp .o nhỏ .

```bash
sh mak obj
# output : pstr.o
```
### biên dịch SO
Tùy chọn này sẽ tạo ra 1 thư viện .
```bash
sh mak so
#output : libpstr.so
```
### biên dịch thông thường
Tùy chọn này sẽ gộp các tệp mã nguồn của picostr và của người dùng gộp lại tạo ra 1 tệp nhị phân
```bash
sh mak test.c -o a.out
```
## Bản quyền
Dự án này được cấp phép theo Giấy phép GNU GPLv3 - xem tệp LICENSE để biết chi tiết.
