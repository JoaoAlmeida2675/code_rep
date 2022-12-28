import os

def update_windows_and_drivers():
    # Update Windows
    os.system("wmic os get Caption")
    os.system("wmic os get csname")
    os.system("wmic os where buildnumber='16299' call upgrade")

    # Update drivers
    os.system("pnputil -i -a driver_folder\driver.inf")

    # Perform clean after updates
    os.system("cleanmgr /sagerun:1")

update_windows_and_drivers()
