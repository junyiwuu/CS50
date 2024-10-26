a = input("File name: ").strip().lower()
if a.endswith("gif"):
    print("image/gif")
elif a.endswith("jpg") or a.endswith("jpeg"):
    print("image/jpeg")
elif a.endswith("png"):
     print("image/png")
elif a.endswith("zip"):
     print("application/zip")
elif a.endswith("txt"):
     print("text/plain")
elif a.endswith("pdf"):
     print("application/pdf")
else:
    print("application/octet-stream")
