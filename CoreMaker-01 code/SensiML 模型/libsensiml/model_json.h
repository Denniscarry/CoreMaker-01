#ifndef __MODEL_JSON_H__
#define __MODEL_JSON_H__

const char recognition_model_string_json[] = {"{\"NumModels\":1,\"ModelIndexes\":{\"0\":\"P_2_RANK_2\"},\"ModelDescriptions\":[{\"Name\":\"P_2_RANK_2\",\"ClassMaps\":{\"1\":\"Rain\",\"2\":\"notRain\",\"0\":\"Unknown\"},\"ModelType\":\"BoostedTreeEnsemble\",\"FeatureFunctions\":[\"MFE\",\"MFE\",\"MFE\",\"MFCC\",\"MFCC\",\"PowerSpectrum\",\"PowerSpectrum\",\"Kurtosis\"]}]}"};

int recognition_model_string_json_len = sizeof(recognition_model_string_json);

#endif /* __MODEL_JSON_H__ */
