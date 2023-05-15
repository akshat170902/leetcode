/**
 * @param {number} millis
 */
async function sleep(millis) {
    let t=Date.now();
    while(Date.now()-t<millis){
        
    }
    
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */