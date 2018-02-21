## Nice to have VM setup

Steps to take to

1. Make your VM scale display size as you resize VirtualBox window
2. Create shared folder with sources to edit files with host OS IDE

### Environment

- Host OS: OSX Sierra
- Lastest (5.2.2) VirtualBox to run VM
- VM: Udacity provided VM

#### Install VirtualBox Additions

1. From the VirtualBox VM window menu select: `Devices -> Insert Guest Additions CD image`

2. Use `blkid` to identify the CD-ROM device. From the guest run:
```
sudo blkid
```
One of the lines in the output should look like this:
```
/dev/sr0: LABEL="VBox_GAs_5.2.2" TYPE="iso9660"
```
The first part (/dev/sr0) is the name of the CD-ROM device.

3. Mount the CD (replace /dev/sr0 by the device name found above):
```
sudo mount /dev/sr0 /media/cdrom/
```

4. Run the Guest Additions installer:
```
sudo /media/cdrom/VBoxLinuxAdditions.run
```

5. Reboot the guest.
```
sudo reboot
```

#### Create shared folder with sources to edit files with host OS IDE

Select `Devices -> Shared Folders`

Click on `Add shared folder`

Choose folder on host OS, set name of share to `SHARENAME`

Create a folder to mount share to
```
sudo mkdir ~/WHATEVER
```

Mount share to guest local folder
```
sudo mount -t vboxsf -o rw,uid=1000,gid=1000 SHARENAME  ~/WHATEVER
```

Without `-o rw,uid=1000,gid=1000` guest OS is unable to write files to host OS shared folder.
