/*
** Copyright 2008, Google Inc.
** Copyright (c) 2009, Code Aurora Forum. All rights reserved.
** Copyright (c) 2010, Ricardo Cerqueira
** Copyright (c) 2011, Ivan Zupan
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
** NOTICE - (RC)
**
** All alterations done to this file to add support for the Z71 terminal
** are intended for use with CyanogenMod. This includes all the support
** for ov5642, and the reverse engineered bits like ioctls and EXIF 
** referred to below as "Values originally from proprietary headers")
** Please do not change the EXIF header without asking me first.
*/

#ifndef ANDROID_HARDWARE_QUALCOMM_CAMERA_HARDWARE_H
#define ANDROID_HARDWARE_QUALCOMM_CAMERA_HARDWARE_H

#include <CameraHardwareInterface.h>
#include <binder/MemoryBase.h>
#include <binder/MemoryHeapBase.h>
#include <stdint.h>

#include <utils/threads.h>
#include <camera/CameraParameters.h>

extern "C" {
#include <linux/android_pmem.h>
#include <msm_camera.h>
}

// Mix and match AOSP/CYANOGEN
const char KEY_PREVIEW_SIZE[] = "preview-size";
const char KEY_SUPPORTED_PREVIEW_SIZES[] = "preview-size-values";
const char KEY_PREVIEW_FORMAT[] = "preview-format";
const char KEY_SUPPORTED_PREVIEW_FORMATS[] = "preview-format-values";
const char KEY_PREVIEW_FRAME_RATE[] = "preview-frame-rate";
const char KEY_SUPPORTED_PREVIEW_FRAME_RATES[] = "preview-frame-rate-values";
const char KEY_PREVIEW_FPS_RANGE[] = "preview-fps-range";
const char KEY_SUPPORTED_PREVIEW_FPS_RANGE[] = "preview-fps-range-values";
const char KEY_PICTURE_SIZE[] = "picture-size";
const char KEY_SUPPORTED_PICTURE_SIZES[] = "picture-size-values";
const char KEY_PICTURE_FORMAT[] = "picture-format";
const char KEY_SUPPORTED_PICTURE_FORMATS[] = "picture-format-values";
const char KEY_JPEG_THUMBNAIL_WIDTH[] = "jpeg-thumbnail-width";
const char KEY_JPEG_THUMBNAIL_HEIGHT[] = "jpeg-thumbnail-height";
const char KEY_SUPPORTED_JPEG_THUMBNAIL_SIZES[] = "jpeg-thumbnail-size-values";
const char KEY_JPEG_THUMBNAIL_QUALITY[] = "jpeg-thumbnail-quality";
const char KEY_JPEG_QUALITY[] = "jpeg-quality";
const char KEY_ROTATION[] = "rotation";
const char KEY_GPS_LATITUDE[] = "gps-latitude";
const char KEY_GPS_LONGITUDE[] = "gps-longitude";
const char KEY_GPS_ALTITUDE[] = "gps-altitude";
const char KEY_GPS_TIMESTAMP[] = "gps-timestamp";
const char KEY_GPS_PROCESSING_METHOD[] = "gps-processing-method";
const char KEY_WHITE_BALANCE[] = "whitebalance";
const char KEY_SUPPORTED_WHITE_BALANCE[] = "whitebalance-values";
const char KEY_EFFECT[] = "effect";
const char KEY_SUPPORTED_EFFECTS[] = "effect-values";
const char KEY_ANTIBANDING[] = "antibanding";
const char KEY_SUPPORTED_ANTIBANDING[] = "antibanding-values";
const char KEY_SCENE_MODE[] = "scene-mode";
const char KEY_SUPPORTED_SCENE_MODES[] = "scene-mode-values";
const char KEY_FLASH_MODE[] = "flash-mode";
const char KEY_SUPPORTED_FLASH_MODES[] = "flash-mode-values";
const char KEY_FOCUS_MODE[] = "focus-mode";
const char KEY_SUPPORTED_FOCUS_MODES[] = "focus-mode-values";
const char KEY_MAX_NUM_FOCUS_AREAS[] = "max-num-focus-areas";
const char KEY_FOCUS_AREAS[] = "focus-areas";
const char KEY_FOCAL_LENGTH[] = "focal-length";
const char KEY_HORIZONTAL_VIEW_ANGLE[] = "horizontal-view-angle";
const char KEY_VERTICAL_VIEW_ANGLE[] = "vertical-view-angle";
const char KEY_SUPPORTED_AUTO_EXPOSURE[] = "auto-exposure-values";
const char KEY_EXPOSURE_COMPENSATION[] = "exposure-compensation";
const char KEY_MAX_EXPOSURE_COMPENSATION[] = "max-exposure-compensation";
const char KEY_MIN_EXPOSURE_COMPENSATION[] = "min-exposure-compensation";
const char KEY_EXPOSURE_COMPENSATION_STEP[] = "exposure-compensation-step";
const char KEY_AUTO_EXPOSURE[] = "auto-exposure";
const char KEY_AUTO_EXPOSURE_LOCK[] = "auto-exposure-lock";
const char KEY_AUTO_EXPOSURE_LOCK_SUPPORTED[] = "auto-exposure-lock-supported";
const char AUTO_EXPOSURE_FRAME_AVG[] = "frame-average";
const char AUTO_EXPOSURE_CENTER_WEIGHTED[] = "center-weighted";
const char AUTO_EXPOSURE_SPOT_METERING[] = "spot-metering";
 // Values for ISO Settings
const char ISO_AUTO[] = "auto";
const char ISO_HJR[] = "ISO_HJR";
const char ISO_100[] = "ISO100";
const char ISO_200[] = "ISO200";
const char ISO_400[] = "ISO400";
const char ISO_800[] = "ISO800";
const char ISO_1600[] = "ISO1600";

 //Values for Lens Shading
const char LENSSHADE_ENABLE[] = "enable";
const char LENSSHADE_DISABLE[] = "disable";

const char KEY_ISO_MODE[] = "iso";
const char KEY_SUPPORTED_ISO_MODES[] = "iso-mode-values";
const char KEY_LENSSHADE[] = "lensshade";
const char KEY_SUPPORTED_LENSSHADE_MODES[] = "lensshade-values";
const char KEY_SHARPNESS[] = "sharpness";
const char KEY_MAX_SHARPNESS[] = "max-sharpness";
const char KEY_CONTRAST[] = "contrast";
const char KEY_MAX_CONTRAST[] = "max-contrast";
const char KEY_SATURATION[] = "saturation";
const char KEY_MAX_SATURATION[] = "max-saturation";

const char KEY_GPS_LATITUDE_REF[] = "gps-latitude-ref";
const char KEY_GPS_LONGITUDE_REF[] = "gps-longitude-ref";
const char KEY_GPS_ALTITUDE_REF[] = "gps-altitude-ref";
const char KEY_GPS_STATUS[] = "gps-status";
const char KEY_EXIF_DATETIME[] = "exif-datetime";

const char KEY_AUTO_WHITEBALANCE_LOCK[] = "auto-whitebalance-lock";
const char KEY_AUTO_WHITEBALANCE_LOCK_SUPPORTED[] = "auto-whitebalance-lock-supported";
const char KEY_MAX_NUM_METERING_AREAS[] = "max-num-metering-areas";
const char KEY_METERING_AREAS[] = "metering-areas";
const char KEY_ZOOM[] = "zoom";
const char KEY_MAX_ZOOM[] = "max-zoom";
const char KEY_ZOOM_RATIOS[] = "zoom-ratios";
const char KEY_ZOOM_SUPPORTED[] = "zoom-supported";
const char KEY_SMOOTH_ZOOM_SUPPORTED[] = "smooth-zoom-supported";
const char KEY_FOCUS_DISTANCES[] = "focus-distances";
const char KEY_VIDEO_FRAME_FORMAT[] = "video-frame-format";
const char KEY_VIDEO_SIZE[] = "video-size";
const char KEY_SUPPORTED_VIDEO_SIZES[] = "video-size-values";
const char KEY_PREFERRED_PREVIEW_SIZE_FOR_VIDEO[] = "preferred-preview-size-for-video";
const char KEY_MAX_NUM_DETECTED_FACES_HW[] = "max-num-detected-faces-hw";
const char KEY_MAX_NUM_DETECTED_FACES_SW[] = "max-num-detected-faces-sw";
const char KEY_RECORDING_HINT[] = "recording-hint";
const char KEY_VIDEO_SNAPSHOT_SUPPORTED[] = "video-snapshot-supported";
const char KEY_VIDEO_STABILIZATION[] = "video-stabilization";
const char KEY_VIDEO_STABILIZATION_SUPPORTED[] = "video-stabilization-supported";

const char TRUE[] = "true";
const char FALSE[] = "false";
const char FOCUS_DISTANCE_INFINITY[] = "Infinity";

// Values for white balance settings.
const char WHITE_BALANCE_AUTO[] = "auto";
const char WHITE_BALANCE_INCANDESCENT[] = "incandescent";
const char WHITE_BALANCE_FLUORESCENT[] = "fluorescent";
const char WHITE_BALANCE_WARM_FLUORESCENT[] = "warm-fluorescent";
const char WHITE_BALANCE_DAYLIGHT[] = "daylight";
const char WHITE_BALANCE_CLOUDY_DAYLIGHT[] = "cloudy-daylight";
const char WHITE_BALANCE_TWILIGHT[] = "twilight";
const char WHITE_BALANCE_SHADE[] = "shade";

// Values for effect settings.
const char EFFECT_NONE[] = "none";
const char EFFECT_MONO[] = "mono";
const char EFFECT_NEGATIVE[] = "negative";
const char EFFECT_SOLARIZE[] = "solarize";
const char EFFECT_SEPIA[] = "sepia";
const char EFFECT_POSTERIZE[] = "posterize";
const char EFFECT_WHITEBOARD[] = "whiteboard";
const char EFFECT_BLACKBOARD[] = "blackboard";
const char EFFECT_AQUA[] = "aqua";

// Values for antibanding settings.
const char ANTIBANDING_AUTO[] = "auto";
const char ANTIBANDING_50HZ[] = "50hz";
const char ANTIBANDING_60HZ[] = "60hz";
const char ANTIBANDING_OFF[] = "off";

// Values for flash mode settings.
const char FLASH_MODE_OFF[] = "off";
const char FLASH_MODE_AUTO[] = "auto";
const char FLASH_MODE_ON[] = "on";
const char FLASH_MODE_RED_EYE[] = "red-eye";
const char FLASH_MODE_TORCH[] = "torch";

// Values for scene mode settings.
const char SCENE_MODE_AUTO[] = "auto";
const char SCENE_MODE_ACTION[] = "action";
const char SCENE_MODE_PORTRAIT[] = "portrait";
const char SCENE_MODE_LANDSCAPE[] = "landscape";
const char SCENE_MODE_NIGHT[] = "night";
const char SCENE_MODE_NIGHT_PORTRAIT[] = "night-portrait";
const char SCENE_MODE_THEATRE[] = "theatre";
const char SCENE_MODE_BEACH[] = "beach";
const char SCENE_MODE_SNOW[] = "snow";
const char SCENE_MODE_SUNSET[] = "sunset";
const char SCENE_MODE_STEADYPHOTO[] = "steadyphoto";
const char SCENE_MODE_FIREWORKS[] = "fireworks";
const char SCENE_MODE_SPORTS[] = "sports";
const char SCENE_MODE_PARTY[] = "party";
const char SCENE_MODE_CANDLELIGHT[] = "candlelight";
const char SCENE_MODE_BARCODE[] = "barcode";

const char PIXEL_FORMAT_YUV422SP[] = "yuv422sp";
const char PIXEL_FORMAT_YUV420SP[] = "yuv420sp";
const char PIXEL_FORMAT_YUV422I[] = "yuv422i-yuyv";
const char PIXEL_FORMAT_YUV420P[]  = "yuv420p";
const char PIXEL_FORMAT_RGB565[] = "rgb565";
const char PIXEL_FORMAT_RGBA8888[] = "rgba8888";
const char PIXEL_FORMAT_JPEG[] = "jpeg";
const char PIXEL_FORMAT_RAW[] = "raw";
const char PIXEL_FORMAT_BAYER_RGGB[] = "bayer-rggb";

// Values for focus mode settings.
const char FOCUS_MODE_AUTO[] = "auto";
const char FOCUS_MODE_NORMAL[] = "normal";
const char FOCUS_MODE_INFINITY[] = "infinity";
const char FOCUS_MODE_MACRO[] = "macro";
const char FOCUS_MODE_FIXED[] = "fixed";
const char FOCUS_MODE_EDOF[] = "edof";
const char FOCUS_MODE_CONTINUOUS_VIDEO[] = "continuous-video";
const char FOCUS_MODE_CONTINUOUS_PICTURE[] = "continuous-picture";

typedef struct image_rect_struct
{
  uint32_t width;      /* Image width */
  uint32_t height;     /* Image height */
} image_rect_type;

struct str_map {
    const char *const desc;
    int val;
};

typedef enum {
    TARGET_MSM7625,
    TARGET_MSM7627,
    TARGET_QSD8250,
    TARGET_MSM7630,
    TARGET_MAX
}targetType;

struct target_map {
    const char *targetStr;
    targetType targetEnum;
};

struct board_property {
    targetType target;
    unsigned int previewSizeMask;
};

/* Values originally in proprietary headers */

#define MSM_CAMERA_CONTROL "/dev/msm_camera/control0"

#define TRUE 1
#define FALSE 0

#define CAMERA_MIN_CONTRAST 0
#define CAMERA_MAX_CONTRAST 4
#define CAMERA_MIN_SHARPNESS 0
#define CAMERA_MIN_EXPOSURE_COMPENSATION -2
#define CAMERA_MAX_SHARPNESS 4
#define CAMERA_MIN_SATURATION 0
#define CAMERA_MAX_SATURATION 4
#define CAMERA_MAX_EXPOSURE_COMPENSATION 2
#define CAMERA_DEF_SHARPNESS 2
#define CAMERA_DEF_CONTRAST 2
#define CAMERA_DEF_SATURATION 2
#define CAMERA_DEF_EXPOSURE_COMPENSATION "0"
#define CAMERA_EXPOSURE_COMPENSATION_STEP 1
#define CAMERA_ERROR_UKNOWN 1

#define CEILING16(x) (x&0xfffffff0)
#define PAD_TO_WORD(x) ((x&1) ? x+1 : x)

#define JPEG_EVENT_DONE 0
#define CAM_CTRL_SUCCESS 1

#define MINIMUM_FPS 10
#define DEFAULT_FPS 15
#define MAXIMUM_FPS 25

// was 4
#define NUM_PREVIEW_BUFFERS 4

typedef struct {
	unsigned int in1_w;
	unsigned int in1_h;
	unsigned int out1_w;
	unsigned int out1_h;
	unsigned int in2_w;
	unsigned int in2_h;
	unsigned int out2_w;
	unsigned int out2_h;
	uint8_t update_flag; 
} common_crop_t;

typedef uint8_t cam_ctrl_type;

typedef struct {
	unsigned short video_width;
	unsigned short video_height;
	unsigned short picture_width;
	unsigned short picture_height;
	unsigned short display_width;
	unsigned short display_height;
	unsigned short orig_picture_dx;
	unsigned short orig_picture_dy;
	unsigned short ui_thumbnail_height;
	unsigned short ui_thumbnail_width;
	unsigned short thumbnail_width;
	unsigned short thumbnail_height;
	unsigned short raw_picture_height;
	unsigned short raw_picture_width;
	unsigned short filler7;
	unsigned short filler8;
} cam_ctrl_dimension_t;

typedef struct {
	uint32_t timestamp;  /* seconds since 1/6/1980          */
	double   latitude;   /* degrees, WGS ellipsoid */
	double   longitude;  /* degrees                */
	int16_t  altitude;   /* meters                          */
} camera_position_type;
typedef uint8_t jpeg_event_t;

typedef enum {
	CAMERA_WB_MIN_MINUS_1,
	CAMERA_WB_AUTO = 1,  /* This list must match aeecamera.h */
	CAMERA_WB_CUSTOM,
	CAMERA_WB_INCANDESCENT,
	CAMERA_WB_FLUORESCENT,
	CAMERA_WB_DAYLIGHT,
	CAMERA_WB_CLOUDY_DAYLIGHT,
	CAMERA_WB_TWILIGHT,
	CAMERA_WB_SHADE,
	CAMERA_WB_MAX_PLUS_1
} camera_wb_type;

typedef enum {
    CAMERA_ANTIBANDING_OFF,
    CAMERA_ANTIBANDING_60HZ,
    CAMERA_ANTIBANDING_50HZ,
    CAMERA_ANTIBANDING_AUTO,
    CAMERA_MAX_ANTIBANDING,
} camera_antibanding_type;

typedef enum {
	AF_MODE_NORMAL,
	AF_MODE_MACRO,
	AF_MODE_AUTO,
} isp3a_af_mode_t;

enum {
	CAMERA_AEC_FRAME_AVERAGE,
	CAMERA_AEC_CENTER_WEIGHTED,
	CAMERA_AEC_SPOT_METERING,
};

enum {
	LED_MODE_OFF,
	LED_MODE_AUTO,
	LED_MODE_ON,
};

typedef enum {
	CAMERA_ISO_AUTO,
	CAMERA_ISO_DEBLUR,
	CAMERA_ISO_100,
	CAMERA_ISO_200,
	CAMERA_ISO_400,
	CAMERA_ISO_800,
	CAMERA_ISO_1600,
} camera_iso_mode_type;

struct fifo_queue {
	int num_of_frames;
	int front;
	struct fifo_node *node;
	pthread_mutex_t mut;
	pthread_cond_t wait;
};

struct fifo_node {
	struct msm_frame *f;
	struct fifo_node *next;
};

void enqueue(struct fifo_queue *queue, struct fifo_node *node) {
	struct fifo_node *cur_node=queue->node;
	int i;
	LOGE("enqueue:%p(%d)\n", node, queue->num_of_frames);
	node->next=NULL;
	if(queue->num_of_frames==0) {
		queue->num_of_frames++;
		queue->front=!!queue->num_of_frames;
		queue->node=node;
		return;
	}
	queue->num_of_frames++;
	queue->front=!!queue->num_of_frames;
	for(i=0;i<(queue->num_of_frames-2);++i) {
		cur_node=cur_node->next;
		assert(!!cur_node);
	}
	cur_node->next=node;
}

struct fifo_node *dequeue(struct fifo_queue *queue) {
	if(queue->num_of_frames==0)
		return NULL;
	struct fifo_node *node=queue->node;
	LOGE("dequeue:%p(%d)\n", node, queue->num_of_frames);
	queue->num_of_frames--;
	queue->front=!!queue->num_of_frames;
	queue->node=queue->node->next;
	return node;
}


enum camera_ops {
    CAMERA_SET_PARM_ENCODE_ROTATION,
    CAMERA_SET_PARM_DIMENSION,
    CAMERA_SET_PARM_ZOOM,
    CAMERA_SET_PARM_SENSOR_POSITION,
    CAMERA_SET_PARM_SHARPNESS,
    CAMERA_SET_PARM_LUMA_ADAPTATION,
    CAMERA_SET_PARM_CONTRAST,
    CAMERA_SET_PARM_EXPOSURE_COMPENSATION,
    CAMERA_SET_PARM_BRIGHTNESS,
    CAMERA_SET_PARM_FOCUS_RECT,
    CAMERA_SET_PARM_HUE,
    CAMERA_SET_PARM_SATURATION,
    CAMERA_SET_PARM_EXPOSURE,
    CAMERA_SET_PARM_AUTO_FOCUS,
    CAMERA_SET_PARM_WB,
    CAMERA_SET_PARM_EFFECT,
    CAMERA_SET_PARM_FPS,
    CAMERA_SET_PARM_FLASH,
    CAMERA_SET_PARM_NIGHTSHOT_MODE,
    CAMERA_SET_PARM_REFLECT,
    CAMERA_SET_PARM_PREVIEW_MODE,
    CAMERA_SET_PARM_ANTIBANDING,
    CAMERA_SET_PARM_RED_EYE_REDUCTION,
    CAMERA_SET_PARM_FOCUS_STEP,
    CAMERA_SET_PARM_EXPOSURE_METERING,
    CAMERA_SET_PARM_AUTO_EXPOSURE_MODE,
    CAMERA_SET_PARM_ISO,
    CAMERA_SET_PARM_BESTSHOT_MODE,
    CAMERA_SET_PARM_PREVIEW_FPS,
    CAMERA_SET_PARM_AF_MODE,
    CAMERA_SET_PARM_HISTOGRAM,
    CAMERA_SET_PARM_FLASH_STATE,
    CAMERA_SET_PARM_FRAME_TIMESTAMP,
    CAMERA_SET_PARM_STROBE_FLASH,
    CAMERA_SET_PARM_FPS_LIST,
    CAMERA_SET_PARM_HJR,
    CAMERA_SET_PARM_ROLLOFF=37,
    CAMERA_STOP_PREVIEW=38,
    CAMERA_START_PREVIEW,
    CAMERA_START_SNAPSHOT,
    CAMERA_START_VIDEO,
    CAMERA_STOP_SNAPSHOT=42,
    CAMERA_EXIT=43,
    CAMERA_STOP_VIDEO,
    CAMERA_START_RECORDING,
    CAMERA_STOP_RECORDING,
    CAMERA_GET_PARM_MAXZOOM,
    CAMERA_START_RAW_SNAPSHOT,
    CAMERA_SET_PARM_LED_MODE,
    CAMERA_GET_PARM_AF_SHARPNESS,
    CAMERA_SET_MOTION_ISO,
    CAMERA_AUTO_FOCUS_CANCEL,
    CAMERA_GET_PARM_FOCUS_STEP,
    CAMERA_ENABLE_AFD,
    CAMERA_PREPARE_SNAPSHOT,
    CAMERA_SET_FPS_MODE,
    CAMERA_SET_PARM_SCENE_MODE,
};

typedef enum {
	CAMERA_RSP_CB_SUCCESS,
	CAMERA_EXIT_CB_DONE,
	CAMERA_EXIT_CB_FAILED,
	CAMERA_EXIT_CB_DSP_IDLE,
	CAMERA_EXIT_CB_DSP_ABORT,
	CAMERA_EXIT_CB_ABORT,
	CAMERA_EXIT_CB_ERROR,
	CAMERA_EVT_CB_FRAME,
	CAMERA_EVT_CB_PICTURE,
	CAMERA_STATUS_CB,
	CAMERA_EXIT_CB_FILE_SIZE_EXCEEDED,
	CAMERA_EXIT_CB_BUFFER,
	CAMERA_EVT_CB_SNAPSHOT_DONE,
	CAMERA_CB_MAX,
} camera_cb_type;

struct cam_frame_start_parms {
	unsigned int unknown;
	struct msm_frame frame;
	struct msm_frame video_frame;
};

typedef unsigned int exif_tag_id_t;

#define EXIF_RATIONAL 5
#define EXIF_ASCII 2
#define EXIF_BYTE 1

typedef struct {
	int val;
	int otherval;
} rat_t;


typedef union {
        char * _ascii; /* At byte 16 relative to exif_tag_entry_t */
        rat_t * _rats;
        rat_t  _rat;
        uint8_t _byte;
} exif_tag_data_t;

/* The entire exif_tag_entry_t struct must be 24 bytes in length */
typedef unsigned int exif_tag_type_t;
typedef struct {
	exif_tag_type_t type;
	uint32_t copy;
	uint32_t count;
	exif_tag_data_t data;
} exif_tag_entry_t;

typedef struct {
	exif_tag_id_t tag_id;
	exif_tag_entry_t tag_entry;
} exif_tags_info_t;

/* EXIF tag IDs */
#define EXIFTAGID_GPS_LATITUDE 0x20002
#define EXIFTAGID_GPS_LATITUDE_REF 0x10001
#define EXIFTAGID_GPS_LONGITUDE 0x40004
#define EXIFTAGID_GPS_LONGITUDE_REF 0x30003
#define EXIFTAGID_GPS_ALTITUDE 0x60006
#define EXIFTAGID_GPS_ALTITUDE_REF 0x50005
#define EXIFTAGID_EXIF_CAMERA_MAKER 0x21010F
#define EXIFTAGID_EXIF_CAMERA_MODEL 0x220110
#define EXIFTAGID_EXIF_DATE_TIME_ORIGINAL 0x3A9003
#define EXIFTAGID_EXIF_DATE_TIME 0x3B9004
/* End of values originally in proprietary headers */

namespace android {

class QualcommCameraHardware : public CameraHardwareInterface {
public:

    virtual sp<IMemoryHeap> getPreviewHeap() const;
    virtual sp<IMemoryHeap> getRawHeap() const;

virtual void setCallbacks(struct camera_device * device,
							camera_notify_callback notify_cb,
							camera_data_callback data_cb, 
							camera_data_timestamp_callback data_cb_timestamp,
							camera_request_memory get_memory,
							void *user);
	virtual void enableMsgType(int32_t msgType);
    virtual void disableMsgType(int32_t msgType);
    virtual bool msgTypeEnabled(int32_t msgType);

    virtual status_t dump(int fd, const Vector<String16>& args) const;
    virtual status_t startPreview();
    virtual void stopPreview();
    virtual bool previewEnabled();
    virtual status_t startRecording();
    virtual void stopRecording();
    virtual bool recordingEnabled();
    virtual void releaseRecordingFrame(const sp<IMemory>& mem);
    virtual status_t autoFocus();
    virtual status_t cancelAutoFocus();
    virtual status_t takePicture();
    virtual status_t cancelPicture();
    virtual status_t setParameters(const CameraParameters& params);
    virtual CameraParameters getParameters() const;
    virtual status_t sendCommand(int32_t command, int32_t arg1, int32_t arg2);
    virtual status_t getBufferInfo( sp<IMemory>& Frame, size_t *alignedSize);

    virtual void release();
    virtual bool useOverlay();
    //virtual status_t setOverlay(const sp<Overlay> &overlay);

    static sp<CameraHardwareInterface> createInstance();
    static sp<QualcommCameraHardware> getInstance();

    void receivePreviewFrame(struct msm_frame *frame);
    void receiveRecordingFrame(struct msm_frame *frame);
    void receiveJpegPicture(void);
    void jpeg_set_location();
    void receiveJpegPictureFragment(uint8_t *buf, uint32_t size);
    void notifyShutter(common_crop_t *crop);
    void receive_camframetimeout();
	



private:
    QualcommCameraHardware();
    virtual ~QualcommCameraHardware();
    status_t startPreviewInternal();
    void stopPreviewInternal();
    friend void *auto_focus_thread(void *user);
    void runAutoFocus();
    status_t cancelAutoFocusInternal();
    bool native_set_dimension (int camfd);
    bool native_jpeg_encode (void);
    bool native_set_parm(int mCameraControlFd, cam_ctrl_type type, uint16_t length, void *value);
    bool native_zoom_image(int fd, int srcOffset, int dstOffset, common_crop_t *crop);

    static wp<QualcommCameraHardware> singleton;

    /* These constants reflect the number of buffers that libmmcamera requires
       for preview and raw, and need to be updated when libmmcamera
       changes.
    */
    static const int kPreviewBufferCount = NUM_PREVIEW_BUFFERS;
    static const int kRawBufferCount = 1;
    static const int kJpegBufferCount = 1;

    int jpegPadding;

    CameraParameters mParameters;
    unsigned int frame_size;
    bool mCameraRunning;
    android::Mutex mCameraRunningLock;
    bool mPreviewInitialized;

    // This class represents a heap which maintains several contiguous
    // buffers.  The heap may be backed by pmem (when pmem_pool contains
    // the name of a /dev/pmem* file), or by ashmem (when pmem_pool == NULL).

    struct MemPool : public RefBase {
        MemPool(int buffer_size, int num_buffers,
                int frame_size,
                const char *name);

        virtual ~MemPool() = 0;

        void completeInitialization();
        bool initialized() const {
            return mHeap != NULL && mHeap->base() != MAP_FAILED;
        }

        virtual status_t dump(int fd, const Vector<String16>& args) const;

        int mBufferSize;
        int mAlignedBufferSize;
        int mNumBuffers;
        int mFrameSize;
        sp<MemoryHeapBase> mHeap;
        sp<MemoryBase> *mBuffers;

        const char *mName;
    };

    struct AshmemPool : public MemPool {
        AshmemPool(int buffer_size, int num_buffers,
                   int frame_size,
                   const char *name);
    };

    struct PmemPool : public MemPool {
        PmemPool(const char *pmem_pool,
                 int control_camera_fd, int flags, int pmem_type,
                 int buffer_size, int num_buffers,
                 int frame_size,
                 const char *name);
        virtual ~PmemPool();
        int mFd;
        int mPmemType;
        int mCameraControlFd;
        uint32_t mAlignedSize;
        struct pmem_region mSize;
    };

    sp<PmemPool> mPreviewHeap;
    sp<PmemPool> mRecordHeap;
    sp<PmemPool> mThumbnailHeap;
    sp<PmemPool> mRawHeap;
    sp<PmemPool> mDisplayHeap;
    sp<AshmemPool> mJpegHeap;
    sp<PmemPool> mRawSnapShotPmemHeap;
    sp<PmemPool> mPostViewHeap;


    bool startCamera();
    bool initPreview();
    bool initRecord();
    void deinitPreview();
    bool initRaw(bool initJpegHeap);
    bool initRawSnapshot();
    void deinitRaw();
    void deinitRawSnapshot();

    bool mFrameThreadRunning;
    Mutex mFrameThreadWaitLock;
    Condition mFrameThreadWait;
    friend void *frame_thread(void *user);
    void runFrameThread(void *data);

    //720p recording video thread
    bool mVideoThreadExit;
    bool mVideoThreadRunning;
    Mutex mVideoThreadWaitLock;
    Condition mVideoThreadWait;
    friend void *video_thread(void *user);
    void runVideoThread(void *data);


    bool mShutterPending;
    Mutex mShutterLock;

    bool mSnapshotThreadRunning;
    Mutex mSnapshotThreadWaitLock;
    Condition mSnapshotThreadWait;
    friend void *snapshot_thread(void *user);
    void runSnapshotThread(void *data);
    Mutex mRawPictureHeapLock;
    bool mJpegThreadRunning;
    Mutex mJpegThreadWaitLock;
    Condition mJpegThreadWait;
    bool mInSnapshotMode;
    Mutex mInSnapshotModeWaitLock;
    Condition mInSnapshotModeWait;

    void debugShowPreviewFPS() const;
    void debugShowVideoFPS() const;

    int mSnapshotFormat;
    void filterPictureSizes();
    void filterPreviewSizes();
    void storeTargetType();

    void initDefaultParameters();
    void findSensorType();

    status_t setPreviewSize(const CameraParameters& params);
    status_t setPreviewFrameRate(const CameraParameters& params);
    status_t setPictureSize(const CameraParameters& params);
    status_t setJpegQuality(const CameraParameters& params);
    status_t setAntibanding(const CameraParameters& params);
    status_t setEffect(const CameraParameters& params);
    status_t setAutoExposure(const CameraParameters& params);
    status_t setWhiteBalance(const CameraParameters& params);
    status_t setFlash(const CameraParameters& params);
    status_t setGpsLocation(const CameraParameters& params);
    status_t setRotation(const CameraParameters& params);
    status_t setZoom(const CameraParameters& params);
    status_t setFocusMode(const CameraParameters& params);
    status_t setBrightness(const CameraParameters& params);
    status_t setExposureCompensation(const CameraParameters& params);
    status_t setOrientation(const CameraParameters& params);
    status_t setLensshadeValue(const CameraParameters& params);
    status_t setISOValue(const CameraParameters& params);
    status_t setPictureFormat(const CameraParameters& params);
    status_t setSharpness(const CameraParameters& params);
    status_t setContrast(const CameraParameters& params);
    status_t setSaturation(const CameraParameters& params);
    void setGpsParameters();
    void storePreviewFrameForPostview();
    bool isValidDimension(int w, int h);

    Mutex mLock;
    Mutex mCamframeTimeoutLock;
    bool camframe_timeout_flag;
    bool mReleasedRecordingFrame;

    void receiveRawPicture(void);
    void receiveRawSnapshot(void);

    Mutex mCallbackLock;
    Mutex mOverlayLock;
	Mutex mRecordLock;
	Mutex mRecordFrameLock;
	Condition mRecordWait;
    Condition mStateWait;

    /* mJpegSize keeps track of the size of the accumulated JPEG.  We clear it
       when we are about to take a picture, so at any time it contains either
       zero, or the size of the last JPEG picture taken.
    */
    uint32_t mJpegSize;
    unsigned int        mPreviewFrameSize;
    unsigned int        mRecordFrameSize;
    int                 mRawSize;
    int                 mJpegMaxSize;

#if DLOPEN_LIBMMCAMERA
    void *libmmcamera;
#endif

    int mCameraControlFd;
    struct msm_camsensor_info mSensorInfo;
    cam_ctrl_dimension_t mDimension;
    bool mAutoFocusThreadRunning;
    Mutex mAutoFocusThreadLock;
    int mAutoFocusFd;

    Mutex mAfLock;

    pthread_t mFrameThread;
    pthread_t mVideoThread;
    pthread_t mSnapshotThread;

    common_crop_t mCrop;

    bool mInitialized;

    int mBrightness;
    int mHJR;
    struct msm_frame frames[kPreviewBufferCount];
    struct msm_frame *recordframes;
    bool mInPreviewCallback;
    bool mUseOverlay;
    //sp<Overlay>  mOverlay;

    int32_t mMsgEnabled;    // camera msg to be handled
    camera_notify_callback mNotifyCallback;
    camera_data_callback mDataCallback;
    camera_data_timestamp_callback mDataCallbackTimestamp;
	camera_request_memory mMemoryCallback;
    void *mCallbackCookie;  // same for all callbacks
    int mDebugFps;
    int kPreviewBufferCountActual;
    int previewWidth, previewHeight;
	
	camera_memory_t * cameraData;
	
	void * tmpMem;


	

	
	
};

}; // namespace android

	
// ICS HAL stuff

static int camera_get_number_of_cameras(void);
static int camera_get_camera_info(int camera_id, struct camera_info *info);
static int camera_device_open(const hw_module_t* module, const char* name, hw_device_t** device);
static int camera_device_close(hw_device_t* device);
static int camera_start_preview(struct camera_device * device);
static char* camera_get_parameters(struct camera_device * device);
static void camera_put_parameters(struct camera_device *device, char *parms);
static int camera_set_parameters(struct camera_device * device, const char *params);
static int camera_send_command(struct camera_device * device, int32_t cmd, int32_t arg1, int32_t arg2);
static int camera_set_preview_window(struct camera_device * device, struct preview_stream_ops *window);
static void camera_stop_preview(struct camera_device * device);
static int camera_auto_focus(struct camera_device * device);
static int camera_cancel_auto_focus(struct camera_device * device);
static int camera_take_picture(struct camera_device * device);
static int camera_cancel_picture(struct camera_device * device);
static void camera_set_callbacks(struct camera_device * device, camera_notify_callback notify_cb,    camera_data_callback data_cb,       camera_data_timestamp_callback data_cb_timestamp,        camera_request_memory get_memory,        void *user);
static int camera_preview_enabled(struct camera_device * device);
static void camera_enable_msg_type(struct camera_device * device, int32_t msg_type);
static void camera_disable_msg_type(struct camera_device * device, int32_t msg_type);
static int camera_msg_type_enabled(struct camera_device * device, int32_t msg_type);
static void camera_release(struct camera_device * device);
static int camera_store_meta_data_in_buffers(struct camera_device * device, int enable);
static int camera_dump(struct camera_device * device, int fd);
static int camera_start_recording(struct camera_device * device);
static void camera_stop_recording(struct camera_device * device);
static int camera_recording_enabled(struct camera_device * device);
static void camera_release_recording_frame(struct camera_device * device, const void *opaque);

// preview ops
static int camera_dequeue_buffer(struct preview_stream_ops* w, buffer_handle_t** buffer, int *stride);
static int camera_enqueue_buffer(struct preview_stream_ops* w, buffer_handle_t* buffer);
static int camera_cancel_buffer(struct preview_stream_ops* w, buffer_handle_t* buffer);
static int camera_set_buffer_count(struct preview_stream_ops* w, int count);
static int camera_set_buffers_geometry(struct preview_stream_ops* pw, int w, int h, int format);
static int camera_set_crop(struct preview_stream_ops *w,  int left, int top, int right, int bottom);
static int camera_set_usage(struct preview_stream_ops* w, int usage);
static int camera_set_swap_interval(struct preview_stream_ops *w, int interval);
static int camera_get_min_undequeued_buffer_count(const struct preview_stream_ops *w, int *count);
static int camera_lock_buffer(struct preview_stream_ops* w, buffer_handle_t* buffer);


// TODO: try casting this again
static android::sp<android::QualcommCameraHardware> camObj;
static android::sp<android::CameraHardwareInterface> tmpObj;
static void * dlHandle;


static struct hw_module_methods_t camera_module_methods = {
		open: camera_device_open
};

camera_module_t HAL_MODULE_INFO_SYM = {
	common: {
		 tag: HARDWARE_MODULE_TAG,
		 version_major: 1,
		 version_minor: 0,
		 id: CAMERA_HARDWARE_MODULE_ID,
		 name: "Camera HAL skeleton module for ICS",
		 author: "Ivan Zupan",
		 methods: &camera_module_methods,
		 dso: NULL,
		 reserved: {0},
	},
	get_number_of_cameras: camera_get_number_of_cameras,
	get_camera_info: camera_get_camera_info,
};		



#endif
