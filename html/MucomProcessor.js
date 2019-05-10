'use strict';

import Module from './mucom88.js';

class MucomProcessor extends AudioWorkletProcessor {
    constructor(options) {
        super(options);

        this.n = 0;
        this.kernel = options.processorOptions;
        this.kernel.initializeAudioBuffer();
    }

    process(inputs, outputs) {
        this.kernel.mix();

        const output = outputs[0];
        output[0] = this.kernel.getAudioBufferPtrL();
        output[1] = this.kernel.getAudioBufferPtrR();

        return true;
    }
}

registerProcessor('mucom-processor', MucomProcessor);


