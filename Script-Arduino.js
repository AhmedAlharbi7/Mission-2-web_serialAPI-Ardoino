let isConnectted = false;
let port;
let writer;
var target_id;
const enc = new TextEncoder();

async function onChangespeech() {
    if (!isConnectted) {
        alert("In order to use this, You have to connect the usb ");
        return;
    }

    try {
        const commandlist = content;
        const commandSplit = commandlist.split(" ")
        const command = commandSplit.slice(-1);
        const computerText = `${command}@`;
        await writer.write(enc.encode(computerText));
    } catch (e) {
        console.log(e);
    }
}
async function onConnectUsb() {
    try {
        const requestOptions = {
            // Filter on devices with the Arduino USB vendor ID.
            filters: [{ usbVendorId: 0x2341 }],
        };


        // Request the Arduino from the user with data rate in bits per second 115200.
        port = await navigator.serial.requestPort(requestOptions);
        await port.open({ baudRate: 115200 });
        writer = port.writable.getWriter();
        isConnectted = true;
    } catch (e) {
        console.log("error", e);
    }
}
